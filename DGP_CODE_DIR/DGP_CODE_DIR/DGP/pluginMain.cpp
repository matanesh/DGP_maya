/////////////////////////////////////
//Copyright (C) Dr. Ofir Weber 2018//
/////////////////////////////////////


#include "stdafx.h"
#include <maya/MFnPlugin.h> //for some reason, I can't put this line in stdafx.h file

#include "Commands/TriangulatePolygonCmd.h"
#include "Nodes/SpaceDeformer2D.h"

#include "Utils/Maya_Macros.h"

#include "Commands/colorMeshVerticesCmd.h"

MStatus initializePlugin(MObject obj)
{ 
	MStatus stat;

	//https://forums.autodesk.com/t5/maya-programming/c-api-not-printing-to-output-window/td-p/4260798/page/2
	cout.set_rdbuf(MStreamUtils::stdOutStream().rdbuf());
	cerr.set_rdbuf(MStreamUtils::stdErrorStream().rdbuf());


	MFnPlugin plugin(obj, "Weber", "2018" , "Any");
	
	REGISTER_NODE(plugin, MPxNode::kDeformerNode, SpaceDeformer2D, NULL);
	REGISTER_COMMAND_WITH_SYNTAX(plugin, TriangulatePolygonCmd);
	REGISTER_COMMAND_WITH_SYNTAX(plugin, colorMeshVerticesCmd);

	return MS::kSuccess;
}

MStatus uninitializePlugin(MObject obj)
{
	MStatus stat;

	MFnPlugin plugin(obj);

	DEREGISTER_NODE(plugin, SpaceDeformer2D);
	DEREGISTER_COMMAND(plugin, TriangulatePolygonCmd);
	DEREGISTER_COMMAND(plugin, colorMeshVerticesCmd);

	return MS::kSuccess;
}

