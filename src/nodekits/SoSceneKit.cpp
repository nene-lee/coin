/**************************************************************************\
 *
 *  Copyright (C) 1998-2000 by Systems in Motion.  All rights reserved.
 *
 *  This file is part of the Coin library.
 *
 *  This file may be distributed under the terms of the Q Public License
 *  as defined by Troll Tech AS of Norway and appearing in the file
 *  LICENSE.QPL included in the packaging of this file.
 *
 *  If you want to use Coin in applications not covered by licenses
 *  compatible with the QPL, you can contact SIM to aquire a
 *  Professional Edition license for Coin.
 *
 *  Systems in Motion AS, Prof. Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ sales@sim.no Voice: +47 22114160 Fax: +47 67172912
 *
\**************************************************************************/

/*!
  \class SoSceneKit SoSceneKit.h Inventor/nodekits/SoSceneKit.h
  \brief The SoSceneKit class ...
  \ingroup nodekits

  FIXME: write class doc
*/

#include <Inventor/nodekits/SoSceneKit.h>
#include <Inventor/nodekits/SoCameraKit.h>
#include <Inventor/nodekits/SoLightKit.h>
#include <Inventor/nodekits/SoShapeKit.h>
#include <Inventor/nodekits/SoNodeKitListPart.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoSwitch.h>
#include <coindefs.h> // COIN_STUB

#if COIN_DEBUG
#include <Inventor/errors/SoDebugError.h>
#endif // COIN_DEBUG

SO_KIT_SOURCE(SoSceneKit);


/*!
  Constructor.
*/
SoSceneKit::SoSceneKit(void)
{
  SO_KIT_INTERNAL_CONSTRUCTOR(SoSceneKit);

  // Note: we must use "" instead of , , to humour MS VisualC++ 6.

  SO_KIT_ADD_CATALOG_ENTRY(topSeparator, SoSeparator, TRUE, this, "", FALSE);
  SO_KIT_ADD_CATALOG_LIST_ENTRY(cameraList, SoSwitch, TRUE, topSeparator, lightList, SoCameraKit, TRUE);
  SO_KIT_ADD_CATALOG_LIST_ENTRY(lightList, SoGroup, TRUE, topSeparator, childList, SoLightKit, TRUE);
  SO_KIT_ADD_CATALOG_LIST_ENTRY(childList, SoGroup, TRUE, topSeparator, "", SoShapeKit, TRUE);
  SO_KIT_ADD_LIST_ITEM_TYPE(childList, SoSeparatorKit);

  SO_KIT_INIT_INSTANCE();
}

/*!
  Destructor.
*/
SoSceneKit::~SoSceneKit()
{
}

// doc from parent
void
SoSceneKit::initClass(void)
{
  SO_KIT_INTERNAL_INIT_CLASS(SoSceneKit);
}

/*!
  Returns the index of the current active camera in cameraList.
*/
int
SoSceneKit::getCameraNumber(void)
{
  SoSwitch *sw = (SoSwitch*)this->getContainerNode(SbName("cameraList"));
  return sw->whichChild.getValue();
}

/*!
  Sets the current active camera in cameraList.
*/
void
SoSceneKit::setCameraNumber(int camnum)
{
  SoSwitch *sw = (SoSwitch*)this->getContainerNode(SbName("cameraList"));
#if COIN_DEBUG && 1 // debug
  if (camnum >= sw->getNumChildren()) {
    SoDebugError::postInfo("SoSceneKit::setCameraNumber",
                           "camera number %d is too large", camnum);
    return;
  }
#endif // debug
  sw->whichChild = camnum;
}

/*!
  Overloaded to return \e TRUE.
*/
SbBool
SoSceneKit::affectsState(void) const
{
  return TRUE;
}
