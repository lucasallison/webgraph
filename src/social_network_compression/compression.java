package social_network_compression;

import java.io.IOException;

import it.unimi.dsi.webgraph.ASCIIGraph;
import it.unimi.dsi.webgraph.ArrayListMutableGraph;
import it.unimi.dsi.webgraph.BVGraph;

class compression {
	
	public static void main(final String args[]) throws IOException {

		String baseName = "/home/lucas/cnr-2000";
		String comprName = "/home/lucas/out.compressed";
		Boolean useBacklinks = true;
		ASCIIGraph inGraph = ASCIIGraph.loadOffline(baseName);
		ArrayListMutableGraph graph = new ArrayListMutableGraph(inGraph); // by copying to a mutable graph, random access is possible
		BVGraph.store(graph.immutableView(), comprName, -1, BVGraph.DEFAULT_MAX_REF_COUNT, useBacklinks ? BVGraph.NO_INTERVALS : BVGraph.DEFAULT_MIN_INTERVAL_LENGTH, -1, 1, 1, null);
	
	}
}