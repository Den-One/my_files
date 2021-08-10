using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Coin : MonoBehaviour
{
	public int count; // number of bals wich can we get
	public AudioClip audioClip;

	private GameObject player;
	private AudioSource audioSource; // work with sound

	private void Start()
	{
		player = GameObject.FindGameObjectWithTag("Player");
		audioSource = player.GetComponent<AudioSource>();
	}
	private void OnTriggerEnter2D(Collider2D collision)
	{
		if (collision.tag == "Player")
		{
			collision.GetComponent<Player>().AddCoin(count);
			audioSource.PlayOneShot(audioClip); // play the sound
			Destroy(gameObject);
		}
	}
}
