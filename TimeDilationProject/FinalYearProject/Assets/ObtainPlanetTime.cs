using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class ObtainPlanetTime : MonoBehaviour {

    GameObject planet;
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
            this.gameObject.GetComponent<Text>().text = planet.GetComponent<PlanetTime>().planetCurrentTime.ToString();
        }
    }
}
