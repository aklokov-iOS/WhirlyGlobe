package com.mousebirdconsulting.maply;

import android.os.*;
import android.app.*;
import android.view.Menu;
//import android.widget.Toast;

/**
 * The MainActivity is a test activity for the Maply library.
 * For a real app, you'll be wanting to make one of these of your own.
 * 
 * @author sjg
 *
 */
public class MainActivity extends Activity 
{
	// Handles drawing, interaction, and so forth for Maply
	MaplyController mapControl;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) 
    {    	
		System.loadLibrary("Maply");
    	
		// Wait for the debugger to catch up
    	try {
			Thread.sleep(10000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	
    	// Create the Maply Controller
    	mapControl = new MaplyController(this);
 
    	// Load all the country outlines on another thread as a test
//    	TestCountries test = new TestCountries(this,mapControl);
//    	test.start();
    	    	
    	// Display remote OSM vector tiles
//    	TestRemoteOSM test = new TestRemoteOSM(this,mapControl);
//    	test.start();
    	
    	// A remote basemap
    	TestRemoteImageTiles test = new TestRemoteImageTiles(this,mapControl);
    	test.start();
    	
        super.onCreate(savedInstanceState);
    }
    
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
//        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    } 
}