<?xml version="1.0"?>
<!-- transform config to wizard xml -->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
  <xsl:output method="xml" omit-xml-declaration="no" indent="yes" />
  <xsl:template match="/">
    <components>
      <xsl:apply-templates select="//component"/>
    </components>
  </xsl:template>
  <!-- remove empty attributes -->
  <xsl:template match="@*">
    <xsl:if test="string-length(.)>0">
      <xsl:copy />
    </xsl:if>
  </xsl:template>
  <!-- nodes -->
  <xsl:template match="node()">
    <xsl:copy>
      <xsl:apply-templates select="@*|node()"/>
    </xsl:copy>
  </xsl:template>
</xsl:stylesheet>
