#include "SelSurfaceCmd.h"

namespace ofx {
namespace piMapper {

SelSurfaceCmd::SelSurfaceCmd(SurfaceManager * surfaceManager, BaseSurface * surfaceToSelect){
	_surfaceManager = surfaceManager;
	_surfaceToSelect = surfaceToSelect;
}

void SelSurfaceCmd::exec(){
	_prevSelectedSurface = _surfaceManager->getSelectedSurface();
	_surfaceManager->selectSurface(_surfaceToSelect);
}

void SelSurfaceCmd::undo(){
	ofLogNotice("SelSurfaceCmd", "undo");
	_surfaceManager->selectSurface(_prevSelectedSurface);
	_surfaceToSelect = 0;
	_prevSelectedSurface = 0;
}

} // namespace piMapper
} // namespace ofx

