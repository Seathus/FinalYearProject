using UnityEngine;
using System.Collections;


public class PlanetTime : MonoBehaviour {

    public float planetCurrentTime;
    private const long c2  = 89875243264;
    // Use this for initialization
    void Start ()
    {
	
	}
	
	// Update is called once per frame
	void Update ()
    {
        //planetCurrentTime += Time.deltaTime / Mathf.Sqrt(1-(Mathf.Pow(27, 2) /c2));
        planetCurrentTime += Time.deltaTime / Mathf.Sqrt(1 - (Mathf.Pow(27, 2) / c2));
    }
}
