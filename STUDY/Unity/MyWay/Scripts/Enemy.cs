using UnityEngine;
using UnityEngine.SceneManagement;

public class Enemy : MonoBehaviour
{
	public int count;
	public float speed;
	public Vector3[] positions;

	private Animator animator;
	private int currentTarget;
	private SpriteRenderer spriteRenderer; // for rotation

	private void Start()
	{
		spriteRenderer = GetComponent<SpriteRenderer>();
		animator = GetComponent<Animator>();
	}

	public void FixedUpdate()
	{
		if (SceneManager.GetActiveScene().buildIndex == 2)
			animator.SetInteger("State", 1);

		if (animator.GetInteger("isDead") == 0)
		{
			transform.position = Vector3.MoveTowards
				(transform.position,
				 positions[currentTarget],
				 speed); // start and finish

			if (transform.position == positions[currentTarget])
			{
				if (currentTarget < positions.Length - 1) // go to next
				{
					currentTarget++;
					spriteRenderer.flipX = false;
				}
				else
				{
					currentTarget = 0; // go to the start
					spriteRenderer.flipX = true;
				}
			}
		}

		if (animator.GetInteger("isDead") == 1)
		{
			// Destroy BoxCollider and make no phisics
			Destroy(gameObject.GetComponent<BoxCollider2D>());
			Destroy(gameObject.GetComponent<Rigidbody2D>());
			Destroy(gameObject, 1f); // enemy is died
		}
	}

	private void OnCollisionEnter2D(Collision2D collision)
	{
		if (collision.gameObject.tag == "Player" && animator.GetInteger("isDead") == 0)
		{
			SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
		}
	}

	private void OnTriggerEnter2D(Collider2D collision)
	{
		if (collision.gameObject.tag == "Player")
		{
			collision.GetComponent<Player>().SpeedBonus();
			collision.GetComponent<Player>().AddCoin(count);
			animator.SetInteger("isDead", 1);
		}
	}
}
