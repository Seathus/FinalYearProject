﻿using UnityEngine;
using System.Collections;

public class SkyBoxScripts : MonoBehaviour {

	// Use this for initialization
	void Start () {
		RenderSettings.skybox = (Material)Resources.Load("Skybox3");
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
