/*!  \file kfbxcamerastereo.h
*/

#ifndef FBXFILESDK_KFBXPLUGINS_KFBXCAMERASTEREO_H
#define FBXFILESDK_KFBXPLUGINS_KFBXCAMERASTEREO_H

/**************************************************************************************

Copyright (C) 2001 - 2009 Autodesk, Inc. and/or its licensors.
All Rights Reserved.

The coded instructions, statements, computer programs, and/or related material 
(collectively the "Data") in these files contain unpublished information 
proprietary to Autodesk, Inc. and/or its licensors, which is protected by 
Canada and United States of America federal copyright law and by international 
treaties. 

The Data may not be disclosed or distributed to third parties, in whole or in
part, without the prior written consent of Autodesk, Inc. ("Autodesk").

THE DATA IS PROVIDED "AS IS" AND WITHOUT WARRANTY.
ALL WARRANTIES ARE EXPRESSLY EXCLUDED AND DISCLAIMED. AUTODESK MAKES NO
WARRANTY OF ANY KIND WITH RESPECT TO THE DATA, EXPRESS, IMPLIED OR ARISING
BY CUSTOM OR TRADE USAGE, AND DISCLAIMS ANY IMPLIED WARRANTIES OF TITLE, 
NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE OR USE. 
WITHOUT LIMITING THE FOREGOING, AUTODESK DOES NOT WARRANT THAT THE OPERATION
OF THE DATA WILL BE UNINTERRUPTED OR ERROR FREE. 

IN NO EVENT SHALL AUTODESK, ITS AFFILIATES, PARENT COMPANIES, LICENSORS
OR SUPPLIERS ("AUTODESK GROUP") BE LIABLE FOR ANY LOSSES, DAMAGES OR EXPENSES
OF ANY KIND (INCLUDING WITHOUT LIMITATION PUNITIVE OR MULTIPLE DAMAGES OR OTHER
SPECIAL, DIRECT, INDIRECT, EXEMPLARY, INCIDENTAL, LOSS OF PROFITS, REVENUE
OR DATA, COST OF COVER OR CONSEQUENTIAL LOSSES OR DAMAGES OF ANY KIND),
HOWEVER CAUSED, AND REGARDLESS OF THE THEORY OF LIABILITY, WHETHER DERIVED
FROM CONTRACT, TORT (INCLUDING, BUT NOT LIMITED TO, NEGLIGENCE), OR OTHERWISE,
ARISING OUT OF OR RELATING TO THE DATA OR ITS USE OR ANY OTHER PERFORMANCE,
WHETHER OR NOT AUTODESK HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH LOSS
OR DAMAGE. 

**************************************************************************************/

#include <fbxfilesdk/components/kbaselib/kaydaradef_h.h>
#include <fbxfilesdk/components/kbaselib/kaydara.h>

#include <fbxfilesdk/kfbxplugins/kfbxnodeattribute.h>
#include <fbxfilesdk/kfbxplugins/kfbxcolor.h>

#include <fbxfilesdk/kfbxmath/kfbxvector4.h>

#include <fbxfilesdk/components/kbaselib/klib/kstring.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

/** \brief This node attribute contains methods for accessing the properties of a stereo camera.
  * \nosubgrouping
  * Generally, a set of stereoRig contains the center camera, the left camera and the right camera.
  * KFbxCameraStereo is used to represent the center camera. The left and right camera could be KFbxCamera.
  * KFbxCameraStereo contains stereo properties.
  * The left and right camera can also be get and set via related methods in KFbxCameraStereo class.
  */
class KFBX_DLL KFbxCameraStereo : public KFbxCamera
{
    KFBXOBJECT_DECLARE(KFbxCameraStereo, KFbxCamera);

public:

    //! Return the type of node attribute which is EAttributeType::eCAMERA_STEREO.
    virtual EAttributeType GetAttributeType() const;

    //! Reset the stereo camera to default values.
    void Reset();


    /** \enum ECameraStereo Types of Stereo camera.
      * - \e eNONE            Disable the stereo effect.(Default value)
      * - \e eCONVERGED       Computes the zero parallax plane by toeing in the cameras.
      * - \e eOFF_AXIS        Computes the convergence plane by shifting the frustum using camera film back.
      * - \e ePARALLEL        A parallel camera setup where there is effectively no convergence plane.
      */
    typedef enum
    {
        eNONE,
        eCONVERGED,
        eOFF_AXIS,
        ePARALLEL
    } ECameraStereo;

    /** Get the left camera which connect to property LeftCamera.
      * \return a pointer to KFbxCamera.
      * \remarks current KFbxCameraStereo should work with two KFbxCamera, left camera and right camera.
      * Use this method to get the left camera.
      */
    KFbxCamera* GetLeftCamera();

    /** Get the right camera which connect to property RightCamera.
      * \return a pointer to KFbxCamera.
      * \remarks current KFbxCameraStereo should work with two KFbxCamera, left camera and right camera.
      * Use this method to get the right camera.
      */
    KFbxCamera* GetRightCamera();

    /** Set the left camera, connect property LeftCamera to pCamera.
	  * \param pCamera The camera to set
      * \return true if it's successful, otherwise return false.
      * \remarks current KFbxCameraStereo should work with two KFbxCamera, left camera and right camera.
      * Use this method to set the left camera.
      */
    bool SetLeftCamera(KFbxCamera* pCamera);

    /** Set the right camera, connect property RightCamera to pCamera.
	  * \param pCamera The camera to set
      * \return true if it's successful, otherwise return false.
      * \remarks current KFbxCameraStereo should work with two KFbxCamera, left camera and right camera.
      * Use this method to set the right camera.
      */
    bool SetRightCamera(KFbxCamera* pCamera);

    /** Get local matrix of left camera.
      * \return KFbxXMatrix.
      * \remarks Use this method to reevaluate the local transformation of left camera.
      */
    KFbxXMatrix GetLeftCameraLocalMatrix();

    /** Get global matrix of left camera.
      * \return KFbxXMatrix.
      * \remarks Use this method to reevaluate the global transformation of left camera.
      */
    KFbxXMatrix GetLeftCameraGlobalMatrix();

    /** Get local matrix of right camera.
      * \return KFbxXMatrix.
      * \remarks Use this method to reevaluate the local transformation of right camera.
      */
    KFbxXMatrix GetRightCameraLocalMatrix();

    /** Get global matrix of right camera.
      * \return KFbxXMatrix.
      * \remarks Use this method to reevaluate the global transformation of right camera.
      */
    KFbxXMatrix GetRightCameraGlobalMatrix();

    /** Get local matrix of stereo camera.
      * \return KFbxXMatrix.
      * \remarks Use this method to reevaluate the local transformation of stereo camera(center camera).
      */
    KFbxXMatrix GetStereoCameraLocalMatrix();

    /** Get global matrix of stereo camera.
    * \return KFbxXMatrix.
    * \remarks Use this method to reevaluate the global transformation of stereo camera(center camera).
    */
    KFbxXMatrix GetStereoCameraGlobalMatrix();

    /** Reevaluate the FilmOffsetX of left camera.
      * It's computed through stereo camera properties.
      * \return Current FilmOffsetX value.
      * \remarks This method does NOT set the FilmOffsetX of left camera
      */
    double ReevaluateLeftCameraFilmOffsetX();

    /** Reevaluate the FilmOffsetX of right camera.
      * It's computed through stereo camera properties.
      * \return Current FilmOffsetX value
      * \remarks this method does NOT set the FilmOffsetX of right camera
      */
    double ReevaluateRightCameraFilmOffsetX();

    //////////////////////////////////////////////////////////////////////////
    //
    // Properties
    //
    //////////////////////////////////////////////////////////////////////////

    // -----------------------------------------------------------------------
    // Stereo and Stereo Adjustments
    // -----------------------------------------------------------------------

    /** This property handles the types of Stereo camera.
      *
      * To access this property do: Stereo.Get().
      * To set this property do: Stereo.Set(ECameraStereo).
      *
      * \remarks Default Value is eOFF_AXIS. It is the safer way to compute stereo image pairs and avoids keystone artifacts.
      */
    KFbxTypedProperty<ECameraStereo>                    Stereo;

    /** This property handles the distance between left and right cameras.
      *
      * To access this property do: InteraxialSeparation.Get().
      * To set this property do: InteraxialSeparation.Set(fbxDouble1).
      *
      * \remarks Default Value is 0.0
      */
    KFbxTypedProperty<fbxDouble1>                       InteraxialSeparation;

    /** This property handles the distance on the camera view axis where the zero parallax plane occurs.
      *
      * To access this property do: ZeroParallax.Get().
      * To set this property do: ZeroParallax.Set(fbxDouble1).
      *
      * \remarks Default Value is 0.0
      */
    KFbxTypedProperty<fbxDouble1>                       ZeroParallax;

    /** This property is to offset the computed toe-in effect when it's in Converged mode.
      *
      * To access this property do: ToeInAdjust.Get().
      * To set this property do: ToeInAdjust.Set(fbxDouble1).
      *
      * \remarks Default Value is 0.0. 
      * This value is specified in degrees and acts as an offset to the computed toe-in.
      */
    KFbxTypedProperty<fbxDouble1>                       ToeInAdjust;

    /** This property handles the film offset for the right camera.
      *
      * To access this property do: FilmOffsetRightCam.Get().
      * To set this property do: FilmOffsetRightCam.Set(fbxDouble1).
      *
      * \remarks Default Value is 0.0
      */
    KFbxTypedProperty<fbxDouble1>                       FilmOffsetRightCam;

    /** This property handles the film offset for the left camera.
      *
      * To access this property do: FilmOffsetLeftCam.Get().
      * To set this property do: FilmOffsetLeftCam.Set(fbxDouble1).
      *
      * \remarks Default Value is 0.0
      */
    KFbxTypedProperty<fbxDouble1>                       FilmOffsetLeftCam;

    /** This property used to control the FilmOffsetX of left and right camera.
      *
      * To access this property do: ZeroOffset.Get().
      * To set this property do: ZeroOffset.Set(fbxDouble1).
      *
      * \remarks its value is always 0.
      */
    KFbxTypedProperty<fbxDouble1>                       ZeroOffset;

    /** This property has the right camera connected to it.
      *
      * To access this property do: GetRightCamera().
      * To set this property do: SetRightCamera(KFbxCamera* pCamera).
      *
      * \remarks they are connected as source objects
      */
    KFbxTypedProperty<fbxReference>                     RightCamera;

    /** This property has the left camera connected to it.
      *
      * To access this property do: GetLeftCamera().
      * To set this property do: SetLeftCamera(KFbxCamera* pCamera).
      *
      * \remarks they are connected as source objects
      */
    KFbxTypedProperty<fbxReference>                     LeftCamera;


    ///////////////////////////////////////////////////////////////////////////////
    //
    //  WARNING!
    //
    //  Anything beyond these lines may not be documented accurately and is
    //  subject to change without notice.
    //
    ///////////////////////////////////////////////////////////////////////////////

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    /** This property handles the precomp file name
    *
    * To access this property do: PrecompFileName.Get().
    * To set this property do: PrecompFileName.Set(fbxString).
    *
    * Default value is ""
    */
    KFbxTypedProperty<fbxString>                        PrecompFileName;

    /** This property handles the relative precomp file name
    *
    * To access this property do: RelativePrecompFileName.Get().
    * To set this property do: RelativePrecompFileName.Set(fbxString).
    *
    * Default value is ""
    */
    KFbxTypedProperty<fbxString>                        RelativePrecompFileName;

public:
    /** connect left and right camera property to stereo camera.
    * \return true if it's successful, otherwise return false.
    * \remarks It's used to connect the left/right camera property [FocalLength, FarPlane, NearPlane, FilmWidth,
    * FilmHeight, FilmSqueezeRatio] to stereo camera.
    * During FBXSDK reevaluating, if ConnectProperties is called, 
    * to get the newest FocalLength property of left camera, please use lLeft_Camera->FocalLength.GetSrcProperty();
    */
    bool ConnectProperties();

    friend class KFbxGlobalCameraSettings;

    // Clone
    virtual KFbxObject* Clone(KFbxObject* pContainer, KFbxObject::ECloneType pCloneType) const;

protected:
    //! Assignment operator.
    KFbxCameraStereo& operator=(KFbxCameraStereo const& pCameraStereo);

    KFbxCameraStereo(KFbxSdkManager& pManager, char const* pName);

    virtual bool ConstructProperties(bool pForceSet);

    /**
    * Used to retrieve the KProperty list from an attribute
    */
    virtual KString     GetTypeName() const;
    virtual KStringList GetTypeFlags() const;

private:
    friend class KFbxNode;
#endif // #ifndef DOXYGEN_SHOULD_SKIP_THIS
};

typedef KFbxCameraStereo* HKFbxCameraStereo;

inline EFbxType FbxTypeOf( KFbxCameraStereo::ECameraStereo const &pItem )         { return eENUM; }

#include <fbxfilesdk/fbxfilesdk_nsend.h>

#endif // FBXFILESDK_KFBXPLUGINS_KFBXCAMERASTEREO_H

