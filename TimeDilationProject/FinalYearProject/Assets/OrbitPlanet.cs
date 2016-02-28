using UnityEngine;
using System.Collections;

public class OrbitPlanet : MonoBehaviour {

    public GameObject orbitTarget;
    public Transform center;
    public Vector3 axis = Vector3.up;
    public Vector3 desiredPosition;
    public float radius;
    public float radiusSpeed;
    public float rotationSpeed = 1.0f;

    void Start()
    {
        
        center = orbitTarget.transform;
        transform.position = (transform.position - center.position).normalized * radius + center.position;
        radius = 20.0f;
        radiusSpeed = 20.0f;
    }

    void Update()
    {
        transform.RotateAround(center.position, axis, rotationSpeed * Time.deltaTime);
        desiredPosition = (transform.position - center.position).normalized * radius + center.position;
        transform.position = Vector3.MoveTowards(transform.position, desiredPosition, Time.deltaTime * radiusSpeed);
    }
}
