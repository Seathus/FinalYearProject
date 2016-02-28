using UnityEngine;
using System.Collections;
using UnityEngine.UI;
public class TimeDilation : MonoBehaviour {

    // Text text;
    float currentTime;

	// Use this for initialization
	void Start ()
    {
	
	}
	
	// Update is called once per frame
	void Update ()
    {
        currentTime += Time.deltaTime;
        this.gameObject.GetComponent<Text>().text = currentTime.ToString();
	}
}
