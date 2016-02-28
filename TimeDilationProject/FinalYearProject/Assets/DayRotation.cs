using UnityEngine;
using System.Collections;

public class DayRotation : MonoBehaviour {
    public float currentTime;
    // Use this for initialization
    void Start ()
    {
	
	}
	
	// Update is called once per frame
	void Update ()
    {
        
        currentTime += Time.deltaTime;
        
	}

	void FixedUpdate()
	{
		this.gameObject.transform.Rotate(0.0f, 0.0f, 2.0f);
	}
}
