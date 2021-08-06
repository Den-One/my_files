using System.Collections;
using System.Collections.Generic;
using UnityEngine;
/* Player can Jump very high and falling down very fast but he can greatly move
 * using Space button */
public class Player : MonoBehaviour
{
	public float speed;
	public float jumpForce; // power of jump

	private bool isGrounded;
	private Rigidbody2D rigidbody2d; // power of weight
									 // work with other object
	private void Start()
	{
		rigidbody2d = GetComponent<Rigidbody2D>();
	}
	private void Update()
	{
		if (Input.GetKeyDown(KeyCode.Space) && isGrounded) // we can jump if we push jump
		{
			Jump();
		}

		// Save gamer's coordionats
		Vector3 position = transform.position;

		// add to saved coordionats player's input from bord
		position.x += Input.GetAxis("Horizontal") * speed;
		position.y += Input.GetAxis("Vertical");

		transform.position = position; // new position
	}
	private void Jump()
	{
		isGrounded = false; // add impulse to the object
		rigidbody2d.AddForce(transform.up * jumpForce, ForceMode2D.Impulse);
	}

	public void OnCollisionEnter2D(Collision2D collision)
	{
		if (collision.gameObject.tag == "Ground")
		{
			isGrounded = true; // we reached the ground
		}
	}
}
