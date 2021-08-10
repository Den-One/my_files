using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class Player : MonoBehaviour
{
	public float speed;
	public float speedBonus;
	public float jumpForce; // power of jump

	private float speedStart;

	private bool isGrounded;
	private Rigidbody2D rigidbody2d; // power of weight
									 // work with other object
	private SpriteRenderer spriteRenderer;
	private Animator animator;

	public int score; // counter of coints
	public Text scoreText;

	public float timerSpeed; // timer of our speed
	public float timerSpeedMax; // Maximum of our speed

	public float timerScale; // Bonus doing
	public float timerScaleMax; // Maximum of our bonus

	private void Start()
	{
		rigidbody2d = GetComponent<Rigidbody2D>();
		spriteRenderer = GetComponent<SpriteRenderer>();
		animator = GetComponent<Animator>();

		speedStart = speed;

		scoreText.text = score.ToString(); // how much coins do we have
	}
	private void Update()
	{
		if (Input.GetKeyDown(KeyCode.Space) && isGrounded) // we can jump if we push jump
		{
			Jump();
		}

		if (Input.GetKeyDown(KeyCode.Escape))
		{
			SceneManager.LoadScene(0); // loading menu
		}

		// Save gamer's coordionats
		Vector3 position = transform.position;

		// add to saved coordionats player's input from bord
		position.x += Input.GetAxis("Horizontal") * speed;

		transform.position = position; // new position

		if (Input.GetAxis("Horizontal") != 0)
		{
			if (Input.GetAxis("Horizontal") > 0) // Right
			{
				spriteRenderer.flipX = false;
			}
			else if (Input.GetAxis("Horizontal") < 0) // Left
			{
				spriteRenderer.flipX = true;
			}

			if (timerScale > 0)
			{
				animator.SetBool("isRunTall", true);
			}
			else
			{
				animator.SetBool("isRunning", true);
			}
			animator.SetInteger("State", 1);
		}
		else
		{
			if (timerScale > 0)
			{
				animator.SetBool("isRunTall", false);
			}
			else
			{
				animator.SetBool("isRunning", false);
			}

			animator.SetInteger("State", 0);
		}

		if (Input.GetKey(KeyCode.Space) || !isGrounded)
		{
			if (timerScale > 0)
			{
				animator.SetTrigger("jumpTall");
			}
			else
			{
				animator.SetTrigger("jump");
			}
		}

		BonusCheck();
	}

	public bool scaleBonusWork = false;
	private void BonusCheck()
	{
		if (timerSpeed > 0)
		{
			speed = speedBonus;
			timerSpeed--;
		}
		else
		{
			speed = speedStart;
		}

		if (timerScale > 0)
		{
			//transform.localScale = new Vector3(1.5f, 1.5f, 1);
			animator.SetBool("isTall", true);
			timerScale--;
		}
		else
		{
			animator.SetBool("isTall", false);
			//transform.localScale = new Vector3(1, 1, 1);
		}

		// make another size !!! not ended
		if (timerScale > 0 && !scaleBonusWork)
		{
			transform.position = transform.position
			+ new Vector3(0, 0.5f, 0);

			gameObject.GetComponent<BoxCollider2D>().size =
			new Vector2(1, 2);

			scaleBonusWork = true;
		}
		else if (timerScale == 0 && scaleBonusWork)
		{
			gameObject.GetComponent<BoxCollider2D>().size =
			new Vector2(0.8125f, 0.9940548f);

			scaleBonusWork = false;
		}
	}
	private void Jump()
	{
		isGrounded = false;
		rigidbody2d.AddForce(transform.up * jumpForce, ForceMode2D.Impulse);
	}

	public void AddCoin(int count)
	{
		score += count;
		scoreText.text = score.ToString();
	}

	public void SpeedBonus()
	{
		timerSpeed = timerSpeedMax;
	}

	public void ScaleBonus()
	{
		timerScale = timerScaleMax;
	}

	public void OnCollisionEnter2D(Collision2D collision)
	{
		if (collision.gameObject.tag == "Ground")
		{
			isGrounded = true; // we reached the ground
		}
	}

	public void OnCollisionExit2D(Collision collision)
	{
		if (collision.gameObject.tag == "Ground")
		{
			isGrounded = false; // we reached the ground
		}
	}
}
