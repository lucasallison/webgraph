package social_network_compression;

import java.io.IOException;

import it.unimi.dsi.webgraph.ASCIIGraph;
import it.unimi.dsi.webgraph.ArrayListMutableGraph;
import it.unimi.dsi.webgraph.BVGraph;

class compression {
	
	public static void main(final String args[]) throws IOException {

		String baseName = "/home/lucas/Github/snacs/webgraph/src/social_network_compression/graphs/slashdot/slashdot-converted.graph-txt";
		String comprName = "/home/lucas/Github/snacs/webgraph/src/social_network_compression/graphs/slashdot/slashdot.compressed";
		ASCIIGraph inGraph = ASCIIGraph.loadOffline(baseName);
		ArrayListMutableGraph graph = new ArrayListMutableGraph(inGraph); // by copying to a mutable graph, random access is possible
		int windowSize = 4;
		int referenceCount = BVGraph.DEFAULT_MAX_REF_COUNT;
		BVGraph.store(graph.immutableView(), comprName, windowSize, referenceCount, BVGraph.DEFAULT_MIN_INTERVAL_LENGTH, -1, 1, 0, null);
	
	}
}