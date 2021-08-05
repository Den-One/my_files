using UnityEngine;

public class ChangeColour : MonoBehaviour
{
	void Start() {} // Do nothing by the time being

    void Update() // Start before print object on sceen
    {
		TakeButtonSignal();
    }
	void TakeButtonSignal()
	{
		if (Input.GetKeyDown(KeyCode.R)) // RED COLOR!
		{
			gameObject.GetComponent<Renderer>().material.color = Color.red;
		}
		else if (Input.GetKeyDown(KeyCode.G)) // GREEN COLOR!
		{
			gameObject.GetComponent<Renderer>().material.color = Color.green;
		}
		else if (Input.GetKeyDown(KeyCode.B)) // BLUE COLOR!
		{
			gameObject.GetComponent<Renderer>().material.color = Color.blue;
		}
		else if (Input.GetKeyDown(KeyCode.W)) // WHITE COLOR!
		{
			gameObject.GetComponent<Renderer>().material.color = Color.white;
		}
		else if (Input.GetKeyDown(KeyCode.L)) // BLACK!
		{
			gameObject.GetComponent<Renderer>().material.color = Color.black;
		}
		else if (Input.GetKeyDown(KeyCode.A)) // GRAY!
		{
			gameObject.GetComponent<Renderer>().material.color = Color.gray;
		}
		else if (Input.GetKeyDown(KeyCode.C)) // SKY BLUE!
		{
			gameObject.GetComponent<Renderer>().material.color = Color.cyan;
		}
		else if (Input.GetKeyDown(KeyCode.Y)) // YELLOW
		{
			gameObject.GetComponent<Renderer>().material.color = Color.yellow;
		}
		else if (Input.GetKeyDown(KeyCode.M)) // PURPURE
		{
			gameObject.GetComponent<Renderer>().material.color = Color.magenta;
		}
		else if (Input.GetKeyDown(KeyCode.Z)) // REMOVE COLOR
		{
			gameObject.GetComponent<Renderer>().material.color = Color.clear;
		}
	}
}
