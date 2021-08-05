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
		if (Input.GetKeyDown(KeyCode.G)) // GREEN COLOR!
		{
			gameObject.GetComponent<Renderer>().material.color = Color.green;
		}
		if (Input.GetKeyDown(KeyCode.B)) // BLUE COLOR!
		{
			gameObject.GetComponent<Renderer>().material.color = Color.blue;
		}
		if (Input.GetKeyDown(KeyCode.W)) // WHITE COLOR!
		{
			gameObject.GetComponent<Renderer>().material.color = Color.white;
		}
		if (Input.GetKeyDown(KeyCode.L)) // BLACK!
		{
			gameObject.GetComponent<Renderer>().material.color = Color.black;
		}
		if (Input.GetKeyDown(KeyCode.A)) // GRAY!
		{
			gameObject.GetComponent<Renderer>().material.color = Color.gray;
		}
		if (Input.GetKeyDown(KeyCode.C)) // SKY BLUE!
		{
			gameObject.GetComponent<Renderer>().material.color = Color.cyan;
		}
		if (Input.GetKeyDown(KeyCode.Y)) // YELLOW
		{
			gameObject.GetComponent<Renderer>().material.color = Color.yellow;
		}
		if (Input.GetKeyDown(KeyCode.M)) // PURPURE
		{
			gameObject.GetComponent<Renderer>().material.color = Color.magenta;
		}
	}
}
