package social_network_compression;

import java.io.IOException;

import it.unimi.dsi.webgraph.ASCIIGraph;
import it.unimi.dsi.webgraph.ArrayListMutableGraph;
import it.unimi.dsi.webgraph.BVGraph;

class compression {
	
	public static void main(final String args[]) throws IOException {

		String baseName = "...";
		String comprName = "...";
		ASCIIGraph inGraph = ASCIIGraph.loadOffline(baseName);
		ArrayListMutableGraph graph = new ArrayListMutableGraph(inGraph);
		int windowSize = 7;
		int referenceCount = 3;
		BVGraph.store(graph.immutableView(), comprName, windowSize, referenceCount, BVGraph.DEFAULT_MIN_INTERVAL_LENGTH, -1, 1, 0, null);
	
	}
}
