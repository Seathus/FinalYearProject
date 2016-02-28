using UnityEngine;
using System.Collections;

public class gravitationalTimeDilation : MonoBehaviour {
    public float objectCurrentTime;
    private const long c2 = 89875243264;

    // Use this for initialization
    void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {


       // float radius = getRadiusOfCurrentInOrbitPlanet();
      //  float gravitationalConstant = getGravitationalConstantOfCurrentInOrbitPlanet();
      //  float massOfInOrbitPlanet = getMassOfInOrbitPlanet();
     //   Debug.Log("PlanetMass: " + massOfInOrbitPlanet);
       // objectCurrentTime += Time.deltaTime * Mathf.Sqrt(1 - ( (2*(gravitationalConstant * massOfInOrbitPlanet)) / (radius *c2)));
        //set Fixed timestep.
        //Time.fixedDeltaTime = 0.02f;

		if (Input.GetKey (KeyCode.F1)) 
		{
			Debug.Log ("SLOWED!");
			Time.fixedDeltaTime = 0.4f;
		}
    }

    void FixedUpdate()
    {
        Debug.Log("Event happened.");
    }

    float getRadiusOfCurrentInOrbitPlanet()
    {
        return transform.parent.GetComponent<Orbit>().radius;
    }

    float getGravitationalConstantOfCurrentInOrbitPlanet()
    {
        return transform.parent.GetComponent<GravitationalPull>().pullForce;
    }

    ulong getMassOfInOrbitPlanet()
    {
        //return transform.parent.GetComponent<PlanetMass>().mass;
        return 200;
    }

}
