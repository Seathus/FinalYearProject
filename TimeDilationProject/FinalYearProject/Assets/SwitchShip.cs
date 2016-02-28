using UnityEngine;
using System.Collections;

public class SwitchShip : MonoBehaviour {

    public Camera ship1;
    public Camera ship2;

    bool ship1Cam;

	// Use this for initialization
	void Start () {
	
	}

    public void switchCam()
    {
        ship1Cam = !ship1Cam;
    }
	
	// Update is called once per frame
	void Update () {
	
        if (ship1Cam)
        {
            ship1.enabled = true;
            ship2.enabled = false;
        }
        else
        {
            ship1.enabled = false;
            ship2.enabled = true;
        }

	}
}
