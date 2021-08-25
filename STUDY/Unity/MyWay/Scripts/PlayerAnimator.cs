using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class PlayerAnimator : MonoBehaviour
{
	private Rigidbody2D rigidbody2d;
	private SpriteRenderer spriteRenderer;
	private Animator animator;

	private void Start()
	{
		rigidbody2d = GetComponent<Rigidbody2D>();
		spriteRenderer = GetComponent<SpriteRenderer>();
		animator = GetComponent<Animator>();
	}

	protected void Jump()
	{
		animator.SetTrigger("jump");
		rigidbody2d.AddForce(transform.up
			* jumpForce, ForceMode2D.Impulse);
	}

	protected void TurnAnimation()
	{
		if (Input.GetAxis("Horizontal") < 0)
		{
			spriteRenderer.flipX = true;
		}
		else if (Input.GetAxis("Horizontal") >= 0)
		{
			spriteRenderer.flipX = false;
		}
	}

	protected void Run()
	{
		animator.SetBool("isRun", true);
	}

	procted void Calm()
	{
		animator.SetBool("isRun", false);
	}
}
