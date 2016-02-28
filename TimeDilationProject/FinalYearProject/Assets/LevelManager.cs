using UnityEngine;
using System.Collections;

public class LevelManager : MonoBehaviour {
    public class Boundary
    {
        public float xMin, xMax, zMin, zMax;
    }

    public GameObject player;
    public GameObject currentTerrain;
    public float speed;
    public float tilt;
    public Boundary boundary;
    // Use this for initialization
    void Start ()
    {
	
	}
    
    // Update is called once per frame
    void Update ()
    {
        if (Input.GetKeyDown(KeyCode.W))
        {
            player.GetComponent<PlayerHandler>().Move();
        }
            
    }
}
