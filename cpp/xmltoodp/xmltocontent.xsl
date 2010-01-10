<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
    xmlns:xlink="http://www.w3.org/1999/xlink"
    xmlns:office="urn:oasis:names:tc:opendocument:xmlns:office:1.0"
    xmlns:draw="urn:oasis:names:tc:opendocument:xmlns:drawing:1.0"
    xmlns:h="http://www.w3.org/1999/xhtml">

<xsl:output method="xml" indent="yes"/>

<!-- call for each slide -->
<xsl:template match="*[@type='SlideContainer']">
  <!-- width and height in inches -->
  <xsl:param name="width" select="//documentAtom/slideSize/x"/>
  <xsl:param name="height" select="//documentAtom/slideSize/y"/>
  <xsl:param name="x" select="'0.5in'"/>
  <xsl:param name="y" select="concat(0.5 + (position()-1)*1.1*$height div 576,'in')"/>
  <draw:page draw:master-page-name="Default">
<!--
 <svg x="{$x}" y="{$y}" width="{$width div 576.0}in" height="{$height div 576.0}in"
        viewBox="0 0 {$width} {$height}" overflow="visible" font-size="96"
          stroke-width='6'>
      <rect width="{$width}" height="{$height}" fill="white" stroke="black" stroke-width="10" />
    <xsl:apply-templates select="drawing/OfficeArtDg/groupShape"/>
-->
  </draw:page>
</xsl:template>

<xsl:template match="/">
  <office:document-content>
    <office:body>
      <office:presentation>
        <xsl:apply-templates
          select="ppt/PowerPointStructs/anon/anon/anon[@type='SlideContainer']"/>
      </office:presentation>
    </office:body>
  </office:document-content>
</xsl:template>

</xsl:stylesheet>
