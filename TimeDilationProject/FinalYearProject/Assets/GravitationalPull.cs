using UnityEngine;
using System.Collections;

public class GravitationalPull : MonoBehaviour {

    public float pullRadius;
    public float pullForce;
    bool pullObject;
    GameObject target;
    Vector3 forceDirection;
	// Use this for initialization
	void Start () {
	
	}




    void OnTriggerEnter(Collider collider)
    {
        if (collider.gameObject.tag == "Player")
        {
            pullObject = true;
            target = collider.gameObject;
            Debug.Log("pull player to Earth");
            //target.GetComponent<Rigidbody>().velocity = Vector3.zero;
            //   Debug.Log("position of player: " + target.GetComponent<Transform>().position);
            //gets the direction the pulled object needs to head toward
           // forceDirection = transform.position - target.GetComponent<Transform>().transform.position;
        }
    }

	
	// Update is called once per frame
	void Update () {
	
        if (pullObject)
        {
           
            // Debug.Log("Force Direction: " + forceDirection);
            //applies gravity force on object using its rigidbody component
          //  target.GetComponent<Transform>().transform.Translate(forceDirection, this.gameObject.transform);
            //target.GetComponent<Rigidbody>().AddForce(forceDirection.normalized * pullForce * Time.fixedDeltaTime);
        }

    }
}
