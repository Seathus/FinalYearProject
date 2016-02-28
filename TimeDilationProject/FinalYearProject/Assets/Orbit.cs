using UnityEngine;
using System.Collections;

public class Orbit : MonoBehaviour {

    public GameObject orbitTarget;
    public Transform center;
    public Vector3 axis = Vector3.up;
    public Vector3 desiredPosition;
    public float radius = 21.0f;
    public float radiusSpeed = 8.0f;
    public float rotationSpeed = -9.92f;

    void Start()
    {
         orbitTarget = GameObject.Find("Sun");
         center = orbitTarget.transform;
         transform.position = (transform.position - center.position).normalized * radius + center.position;
         //radius = 2861.0f;
         //radiusSpeed = 80.0f;

        
    }

    void Update()
    {
        transform.RotateAround(center.position, axis, rotationSpeed  );
          desiredPosition = (transform.position - center.position).normalized * radius + center.position;
         transform.position = Vector3.MoveTowards(transform.position, desiredPosition, Time.deltaTime * radiusSpeed);
        


        
    }
}
