using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class PlayerController : PlayerAnimator
{
	public float speed;
	public float jumpForce;

	private void Update()
	{
		Vector3 position = transform.position; // Save and Add
		position.x += Input.GetAxis("Horizontal") * speed;
		transform.position = position; // new position

		if (Input.GetKeyDown(KeyCode.Space) && isGrounded)
		{
			Jump();
		}

		if (Input.GetAxis("Horizontal") != 0)
		{
			TurnAnimation();
			Run();
		}
		else
		{
			Calm();
		}
	}

	private bool isGrounded;

	private bool CheckIsGrounded()
	{
		return isGrounded;
	}

	private void OnCollisionEnter2D(Collision2D collision)
	{
		if (collision.gameObject.tag == "Ground")
		{
			isGrounded = true; // we reached the ground
		}
	}

	private void OnCollisionExit2D(UnityEngine.Collision2D collision)
	{
		if (collision.gameObject.tag == "Ground")
		{
			isGrounded = false; // we left the ground
		}
	}	
}
