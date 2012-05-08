set PATH=%windir%\Microsoft.NET\Framework\v2.0.50727;%DXROOT%\ProductionTools;
if exist output rmdir output /s /q

XslTransform.exe /xsl:"%DXROOT%\ProductionTransforms\ApplyVSDocModel.xsl" reflection.org /xsl:"%DXROOT%\ProductionTransforms\AddFriendlyFilenames.xsl" /out:reflection.xml /arg:IncludeAllMembersTopic=true /arg:IncludeInheritedOverloadTopics=true
XslTransform.exe /xsl:"%DXROOT%\ProductionTransforms\ReflectionToManifest.xsl" reflection.xml /out:manifest.xml
XslTransform.exe /xsl:"%DXROOT%\ProductionTransforms\createvstoc.xsl" reflection.xml /out:toc.xml
call "%DXROOT%\Presentation\vs2005\copyOutput.bat
BuildAssembler.exe  /config:""%DXROOT%\Presentation\vs2005\configuration\sandcastle-mhsc.config" manifest.xml
