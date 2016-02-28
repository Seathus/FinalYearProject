using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class InsidePlanetText : MonoBehaviour {

    GameObject insidePlanet;
    bool planetCollided;
	// Use this for initialization
	void Start ()
    {
	
	}
	
	// Update is called once per frame
	void Update ()
    {
        //Not complete. need to fix targeting and falling towards planet first.
        if (planetCollided)
        {
            this.gameObject.GetComponent<Text>().text = insidePlanet.gameObject.name;
        }
        
    }
}
