using UnityEngine;
using System.Collections;

public class TerrainCreator : MonoBehaviour {
    public GameObject currentTerrain;
    public GameObject newTerrain;
    // Use this for initialization
    void Start () {
        currentTerrain = this.transform.parent.gameObject;
        newTerrain = Instantiate(Resources.Load("Level")) as GameObject;

    }
	
    void OnCollisionEnter(Collision collision)
    {
        // if (collision.gameObject.tag == "Player")
        //    {
        Debug.Log("madeTerrain");
        Terrain terr = currentTerrain.GetComponent<Terrain>();
        Instantiate(newTerrain, new Vector3(currentTerrain.transform.position.x, currentTerrain.transform.position.y, terr.terrainData.size.z), Quaternion.identity);
     //   }
        
    }

	// Update is called once per frame
	void Update () {
	
	}
}
