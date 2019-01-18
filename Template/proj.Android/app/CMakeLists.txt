# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

include_directories(${ANDROID_NDK}/sources/android/native_app_glue/)
include_directories(../../Irrlicht/)
include_directories(../../Irrlicht/include)
include_directories(../../Irrlicht/Android)
include_directories(../../Irrlicht/aesGladman/)
include_directories(../../Irrlicht/jpeglib/)
include_directories(../../Irrlicht/libpng/)
include_directories(../../Irrlicht/zlib/)

include_directories(../../Classes/)
include_directories(src/main/cpp/)

add_library( # Sets the name of the library.
             app-glue

             # Sets the library as a shared library.
             STATIC

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c )

add_library(irr STATIC
        ../../Irrlicht/Android/CIrrDeviceAndroid.cpp
        ../../Irrlicht/Android/CAndroidAssetReader.cpp
        ../../Irrlicht/Android/CAndroidAssetFileArchive.cpp
        ../../Irrlicht/Android/CKeyEventWrapper.cpp
        ../../Irrlicht/aesGladman/aescrypt.cpp
        ../../Irrlicht/aesGladman/aeskey.cpp
        ../../Irrlicht/aesGladman/aestab.cpp
        ../../Irrlicht/aesGladman/fileenc.cpp
        ../../Irrlicht/aesGladman/hmac.cpp
        ../../Irrlicht/aesGladman/prng.cpp
        ../../Irrlicht/aesGladman/pwd2key.cpp
        ../../Irrlicht/aesGladman/sha1.cpp
        ../../Irrlicht/aesGladman/sha2.cpp
        ../../Irrlicht/C3DSMeshFileLoader.cpp
        ../../Irrlicht/CAnimatedMeshHalfLife.cpp
        ../../Irrlicht/CAnimatedMeshMD2.cpp
        ../../Irrlicht/CAnimatedMeshMD3.cpp
        ../../Irrlicht/CAnimatedMeshSceneNode.cpp
        ../../Irrlicht/CAttributes.cpp
        ../../Irrlicht/CB3DMeshFileLoader.cpp
        ../../Irrlicht/CB3DMeshWriter.cpp
        ../../Irrlicht/CBillboardSceneNode.cpp
        ../../Irrlicht/CBoneSceneNode.cpp
        ../../Irrlicht/CBSPMeshFileLoader.cpp
        ../../Irrlicht/CBurningShader_Raster_Reference.cpp
        ../../Irrlicht/CCameraSceneNode.cpp
        ../../Irrlicht/CColladaFileLoader.cpp
        ../../Irrlicht/CColladaMeshWriter.cpp
        ../../Irrlicht/CColorConverter.cpp
        ../../Irrlicht/CCSMLoader.cpp
        ../../Irrlicht/CCubeSceneNode.cpp
        ../../Irrlicht/CD3D9Driver.cpp
        ../../Irrlicht/CD3D9HLSLMaterialRenderer.cpp
        ../../Irrlicht/CD3D9NormalMapRenderer.cpp
        ../../Irrlicht/CD3D9ParallaxMapRenderer.cpp
        ../../Irrlicht/CD3D9ShaderMaterialRenderer.cpp
        ../../Irrlicht/CD3D9Texture.cpp
        ../../Irrlicht/CDefaultGUIElementFactory.cpp
        ../../Irrlicht/CDefaultSceneNodeAnimatorFactory.cpp
        ../../Irrlicht/CDefaultSceneNodeFactory.cpp
        ../../Irrlicht/CDepthBuffer.cpp
        ../../Irrlicht/CDMFLoader.cpp
        ../../Irrlicht/CDummyTransformationSceneNode.cpp
        ../../Irrlicht/CEmptySceneNode.cpp
        ../../Irrlicht/CFileList.cpp
        ../../Irrlicht/CFileSystem.cpp
        ../../Irrlicht/CFPSCounter.cpp
        ../../Irrlicht/leakHunter.cpp
        ../../Irrlicht/CGeometryCreator.cpp
        ../../Irrlicht/CGUIButton.cpp
        ../../Irrlicht/CGUICheckBox.cpp
        ../../Irrlicht/CGUIColorSelectDialog.cpp
        ../../Irrlicht/CGUIComboBox.cpp
        ../../Irrlicht/CGUIContextMenu.cpp
        ../../Irrlicht/CGUIEditBox.cpp
        ../../Irrlicht/CGUIEnvironment.cpp
        ../../Irrlicht/CGUIFileOpenDialog.cpp
        ../../Irrlicht/CGUIFont.cpp
        ../../Irrlicht/CGUIImage.cpp
        ../../Irrlicht/CGUIImageList.cpp
        ../../Irrlicht/CGUIInOutFader.cpp
        ../../Irrlicht/CGUIListBox.cpp
        ../../Irrlicht/CGUIMenu.cpp
        ../../Irrlicht/CGUIMeshViewer.cpp
        ../../Irrlicht/CGUIMessageBox.cpp
        ../../Irrlicht/CGUIModalScreen.cpp
        ../../Irrlicht/CGUIScrollBar.cpp
        ../../Irrlicht/CGUISkin.cpp
        ../../Irrlicht/CGUISpinBox.cpp
        ../../Irrlicht/CGUISpriteBank.cpp
        ../../Irrlicht/CGUIStaticText.cpp
        ../../Irrlicht/CGUITabControl.cpp
        ../../Irrlicht/CGUITable.cpp
        ../../Irrlicht/CGUIToolBar.cpp
        ../../Irrlicht/CGUITreeView.cpp
        ../../Irrlicht/CGUIWindow.cpp
        ../../Irrlicht/CGUIProfiler.cpp
        ../../Irrlicht/CImage.cpp
        ../../Irrlicht/CImageLoaderBMP.cpp
        ../../Irrlicht/CImageLoaderDDS.cpp
        ../../Irrlicht/CImageLoaderJPG.cpp
        ../../Irrlicht/CImageLoaderPCX.cpp
        ../../Irrlicht/CImageLoaderPNG.cpp
        ../../Irrlicht/CImageLoaderPPM.cpp
        ../../Irrlicht/CImageLoaderPSD.cpp
        ../../Irrlicht/CImageLoaderRGB.cpp
        ../../Irrlicht/CImageLoaderTGA.cpp
        ../../Irrlicht/CImageLoaderWAL.cpp
        ../../Irrlicht/CImageWriterBMP.cpp
        ../../Irrlicht/CImageWriterJPG.cpp
        ../../Irrlicht/CImageWriterPCX.cpp
        ../../Irrlicht/CImageWriterPNG.cpp
        ../../Irrlicht/CImageWriterPPM.cpp
        ../../Irrlicht/CImageWriterPSD.cpp
        ../../Irrlicht/CImageWriterTGA.cpp
        ../../Irrlicht/CImageLoaderPVR.cpp
        ../../Irrlicht/CIrrDeviceConsole.cpp
        ../../Irrlicht/CIrrDeviceFB.cpp
        ../../Irrlicht/CIrrDeviceLinux.cpp
        ../../Irrlicht/CIrrDeviceSDL.cpp
        ../../Irrlicht/CIrrDeviceStub.cpp
        ../../Irrlicht/CIrrDeviceWin32.cpp
        ../../Irrlicht/CIrrMeshFileLoader.cpp
        ../../Irrlicht/CIrrMeshWriter.cpp
        ../../Irrlicht/CLightSceneNode.cpp
        ../../Irrlicht/CLimitReadFile.cpp
        ../../Irrlicht/CLMTSMeshFileLoader.cpp
        ../../Irrlicht/CLogger.cpp
        ../../Irrlicht/CLWOMeshFileLoader.cpp
        ../../Irrlicht/CMD2MeshFileLoader.cpp
        ../../Irrlicht/CMD3MeshFileLoader.cpp
        ../../Irrlicht/CMemoryFile.cpp
        ../../Irrlicht/CMeshCache.cpp
        ../../Irrlicht/CMeshManipulator.cpp
        ../../Irrlicht/CMeshSceneNode.cpp
        ../../Irrlicht/CMeshTextureLoader.cpp
        ../../Irrlicht/CMetaTriangleSelector.cpp
        ../../Irrlicht/CMountPointReader.cpp
        ../../Irrlicht/CMS3DMeshFileLoader.cpp
        ../../Irrlicht/CMY3DMeshFileLoader.cpp
        ../../Irrlicht/CNPKReader.cpp
        ../../Irrlicht/CNullDriver.cpp
        ../../Irrlicht/COBJMeshFileLoader.cpp
        ../../Irrlicht/COBJMeshWriter.cpp
        ../../Irrlicht/COCTLoader.cpp
        ../../Irrlicht/COctreeSceneNode.cpp
        ../../Irrlicht/COctreeTriangleSelector.cpp
        ../../Irrlicht/CEGLManager.cpp
        ../../Irrlicht/COGLES2Driver.cpp
        ../../Irrlicht/COGLES2ExtensionHandler.cpp
        ../../Irrlicht/COGLES2MaterialRenderer.cpp
        ../../Irrlicht/COGLES2FixedPipelineRenderer.cpp
        ../../Irrlicht/COGLES2NormalMapRenderer.cpp
        ../../Irrlicht/COGLES2ParallaxMapRenderer.cpp
        ../../Irrlicht/COGLES2Renderer2D.cpp
        ../../Irrlicht/COGLESDriver.cpp
        ../../Irrlicht/COGLESExtensionHandler.cpp
        ../../Irrlicht/COgreMeshFileLoader.cpp
        ../../Irrlicht/COpenGLCacheHandler.cpp
        ../../Irrlicht/COpenGLDriver.cpp
        ../../Irrlicht/COpenGLExtensionHandler.cpp
        ../../Irrlicht/COpenGLNormalMapRenderer.cpp
        ../../Irrlicht/COpenGLParallaxMapRenderer.cpp
        ../../Irrlicht/COpenGLShaderMaterialRenderer.cpp
        ../../Irrlicht/COpenGLSLMaterialRenderer.cpp
        ../../Irrlicht/COSOperator.cpp
        ../../Irrlicht/CPakReader.cpp
        ../../Irrlicht/CParticleAnimatedMeshSceneNodeEmitter.cpp
        ../../Irrlicht/CParticleAttractionAffector.cpp
        ../../Irrlicht/CParticleBoxEmitter.cpp
        ../../Irrlicht/CParticleCylinderEmitter.cpp
        ../../Irrlicht/CParticleFadeOutAffector.cpp
        ../../Irrlicht/CParticleGravityAffector.cpp
        ../../Irrlicht/CParticleMeshEmitter.cpp
        ../../Irrlicht/CParticlePointEmitter.cpp
        ../../Irrlicht/CParticleRingEmitter.cpp
        ../../Irrlicht/CParticleRotationAffector.cpp
        ../../Irrlicht/CParticleScaleAffector.cpp
        ../../Irrlicht/CParticleSphereEmitter.cpp
        ../../Irrlicht/CParticleSystemSceneNode.cpp
        ../../Irrlicht/CPLYMeshFileLoader.cpp
        ../../Irrlicht/CPLYMeshWriter.cpp
        ../../Irrlicht/CProfiler.cpp
        ../../Irrlicht/CQ3LevelMesh.cpp
        ../../Irrlicht/CQuake3ShaderSceneNode.cpp
        ../../Irrlicht/CReadFile.cpp
        ../../Irrlicht/CSceneCollisionManager.cpp
        ../../Irrlicht/CSceneLoaderIrr.cpp
        ../../Irrlicht/CSceneManager.cpp
        ../../Irrlicht/CSceneNodeAnimatorCameraFPS.cpp
        ../../Irrlicht/CSceneNodeAnimatorCameraMaya.cpp
        ../../Irrlicht/CSceneNodeAnimatorCollisionResponse.cpp
        ../../Irrlicht/CSceneNodeAnimatorDelete.cpp
        ../../Irrlicht/CSceneNodeAnimatorFlyCircle.cpp
        ../../Irrlicht/CSceneNodeAnimatorFlyStraight.cpp
        ../../Irrlicht/CSceneNodeAnimatorFollowSpline.cpp
        ../../Irrlicht/CSceneNodeAnimatorRotation.cpp
        ../../Irrlicht/CSceneNodeAnimatorTexture.cpp
        ../../Irrlicht/CShadowVolumeSceneNode.cpp
        ../../Irrlicht/CSkinnedMesh.cpp
        ../../Irrlicht/CSkyBoxSceneNode.cpp
        ../../Irrlicht/CSkyDomeSceneNode.cpp
        ../../Irrlicht/CSMFMeshFileLoader.cpp
        ../../Irrlicht/CSoftwareDriver.cpp
        ../../Irrlicht/CSoftwareDriver2.cpp
        ../../Irrlicht/CSoftwareTexture.cpp
        ../../Irrlicht/CSoftwareTexture2.cpp
        ../../Irrlicht/CSphereSceneNode.cpp
        ../../Irrlicht/CSTLMeshFileLoader.cpp
        ../../Irrlicht/CSTLMeshWriter.cpp
        ../../Irrlicht/CTarReader.cpp
        ../../Irrlicht/CTerrainSceneNode.cpp
        ../../Irrlicht/CTerrainTriangleSelector.cpp
        ../../Irrlicht/CTextSceneNode.cpp
        ../../Irrlicht/CTRFlat.cpp
        ../../Irrlicht/CTRFlatWire.cpp
        ../../Irrlicht/CTRGouraud.cpp
        ../../Irrlicht/CTRGouraud2.cpp
        ../../Irrlicht/CTRGouraudAlpha2.cpp
        ../../Irrlicht/CTRGouraudAlphaNoZ2.cpp
        ../../Irrlicht/CTRGouraudWire.cpp
        ../../Irrlicht/CTriangleBBSelector.cpp
        ../../Irrlicht/CTriangleSelector.cpp
        ../../Irrlicht/CTRNormalMap.cpp
        ../../Irrlicht/CTRStencilShadow.cpp
        ../../Irrlicht/CTRTextureBlend.cpp
        ../../Irrlicht/CTRTextureDetailMap2.cpp
        ../../Irrlicht/CTRTextureFlat.cpp
        ../../Irrlicht/CTRTextureFlatWire.cpp
        ../../Irrlicht/CTRTextureGouraud.cpp
        ../../Irrlicht/CTRTextureGouraud2.cpp
        ../../Irrlicht/CTRTextureGouraudAdd.cpp
        ../../Irrlicht/CTRTextureGouraudAdd2.cpp
        ../../Irrlicht/CTRTextureGouraudAddNoZ2.cpp
        ../../Irrlicht/CTRTextureGouraudAlpha.cpp
        ../../Irrlicht/CTRTextureGouraudAlphaNoZ.cpp
        ../../Irrlicht/CTRTextureGouraudNoZ.cpp
        ../../Irrlicht/CTRTextureGouraudNoZ2.cpp
        ../../Irrlicht/CTRTextureGouraudVertexAlpha2.cpp
        ../../Irrlicht/CTRTextureGouraudWire.cpp
        ../../Irrlicht/CTRTextureLightMap2_Add.cpp
        ../../Irrlicht/CTRTextureLightMap2_M1.cpp
        ../../Irrlicht/CTRTextureLightMap2_M2.cpp
        ../../Irrlicht/CTRTextureLightMap2_M4.cpp
        ../../Irrlicht/CTRTextureLightMapGouraud2_M4.cpp
        ../../Irrlicht/CTRTextureWire2.cpp
        ../../Irrlicht/CVideoModeList.cpp
        ../../Irrlicht/CVolumeLightSceneNode.cpp
        ../../Irrlicht/CWADReader.cpp
        ../../Irrlicht/CWaterSurfaceSceneNode.cpp
        ../../Irrlicht/CWriteFile.cpp
        ../../Irrlicht/CXMeshFileLoader.cpp
        ../../Irrlicht/CXMLReader.cpp
        ../../Irrlicht/CXMLWriter.cpp
        ../../Irrlicht/CZBuffer.cpp
        ../../Irrlicht/CZipReader.cpp
        ../../Irrlicht/IBurningShader.cpp
        ../../Irrlicht/Irrlicht.cpp
        ../../Irrlicht/irrXML.cpp
        ../../Irrlicht/os.cpp
        ../../Irrlicht/bzip2/blocksort.c
        ../../Irrlicht/bzip2/bzcompress.c
        ../../Irrlicht/bzip2/bzlib.c
        ../../Irrlicht/bzip2/crctable.c
        ../../Irrlicht/bzip2/decompress.c
        ../../Irrlicht/bzip2/huffman.c
        ../../Irrlicht/bzip2/randtable.c
        ../../Irrlicht/jpeglib/jaricom.c
        ../../Irrlicht/jpeglib/jcapimin.c
        ../../Irrlicht/jpeglib/jcapistd.c
        ../../Irrlicht/jpeglib/jcarith.c
        ../../Irrlicht/jpeglib/jccoefct.c
        ../../Irrlicht/jpeglib/jccolor.c
        ../../Irrlicht/jpeglib/jcdctmgr.c
        ../../Irrlicht/jpeglib/jchuff.c
        ../../Irrlicht/jpeglib/jcinit.c
        ../../Irrlicht/jpeglib/jcmainct.c
        ../../Irrlicht/jpeglib/jcmarker.c
        ../../Irrlicht/jpeglib/jcmaster.c
        ../../Irrlicht/jpeglib/jcomapi.c
        ../../Irrlicht/jpeglib/jcparam.c
        ../../Irrlicht/jpeglib/jcprepct.c
        ../../Irrlicht/jpeglib/jcsample.c
        ../../Irrlicht/jpeglib/jctrans.c
        ../../Irrlicht/jpeglib/jdapimin.c
        ../../Irrlicht/jpeglib/jdapistd.c
        ../../Irrlicht/jpeglib/jdarith.c
        ../../Irrlicht/jpeglib/jdatadst.c
        ../../Irrlicht/jpeglib/jdatasrc.c
        ../../Irrlicht/jpeglib/jdcoefct.c
        ../../Irrlicht/jpeglib/jdcolor.c
        ../../Irrlicht/jpeglib/jddctmgr.c
        ../../Irrlicht/jpeglib/jdhuff.c
        ../../Irrlicht/jpeglib/jdinput.c
        ../../Irrlicht/jpeglib/jdmainct.c
        ../../Irrlicht/jpeglib/jdmarker.c
        ../../Irrlicht/jpeglib/jdmaster.c
        ../../Irrlicht/jpeglib/jdmerge.c
        ../../Irrlicht/jpeglib/jdpostct.c
        ../../Irrlicht/jpeglib/jdsample.c
        ../../Irrlicht/jpeglib/jdtrans.c
        ../../Irrlicht/jpeglib/jerror.c
        ../../Irrlicht/jpeglib/jfdctflt.c
        ../../Irrlicht/jpeglib/jfdctfst.c
        ../../Irrlicht/jpeglib/jfdctint.c
        ../../Irrlicht/jpeglib/jidctflt.c
        ../../Irrlicht/jpeglib/jidctfst.c
        ../../Irrlicht/jpeglib/jidctint.c
        ../../Irrlicht/jpeglib/jmemmgr.c
        ../../Irrlicht/jpeglib/jmemnobs.c
        ../../Irrlicht/jpeglib/jquant1.c
        ../../Irrlicht/jpeglib/jquant2.c
        ../../Irrlicht/jpeglib/jutils.c
        ../../Irrlicht/libpng/png.c
        ../../Irrlicht/libpng/pngerror.c
        ../../Irrlicht/libpng/pngget.c
        ../../Irrlicht/libpng/pngmem.c
        ../../Irrlicht/libpng/pngpread.c
        ../../Irrlicht/libpng/pngread.c
        ../../Irrlicht/libpng/pngrio.c
        ../../Irrlicht/libpng/pngrtran.c
        ../../Irrlicht/libpng/pngrutil.c
        ../../Irrlicht/libpng/pngset.c
        ../../Irrlicht/libpng/pngtrans.c
        ../../Irrlicht/libpng/pngwio.c
        ../../Irrlicht/libpng/pngwrite.c
        ../../Irrlicht/libpng/pngwtran.c
        ../../Irrlicht/libpng/pngwutil.c
        ../../Irrlicht/lzma/LzmaDec.c
        ../../Irrlicht/zlib/adler32.c
        ../../Irrlicht/zlib/crc32.c
        ../../Irrlicht/zlib/gzclose.c
        ../../Irrlicht/zlib/gzread.c
        ../../Irrlicht/zlib/infback.c
        ../../Irrlicht/zlib/inflate.c
        ../../Irrlicht/zlib/trees.c
        ../../Irrlicht/zlib/zutil.c
        ../../Irrlicht/zlib/compress.c
        ../../Irrlicht/zlib/deflate.c
        ../../Irrlicht/zlib/gzlib.c
        ../../Irrlicht/zlib/gzwrite.c
        ../../Irrlicht/zlib/inffast.c
        ../../Irrlicht/zlib/inftrees.c
        ../../Irrlicht/zlib/uncompr.c)

file(GLOB CLASSES_PATH "../../Classes/*.cpp", "src/main/cpp/*.cpp")

add_library(native-lib SHARED ${CLASSES_PATH})

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

find_library(android-lib android)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries(irr ${android-lib} EGL GLESv1_CM GLESv2 ${log-lib})
target_link_libraries(native-lib app-glue irr)