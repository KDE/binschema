<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
    xmlns:xlink="http://www.w3.org/1999/xlink" xmlns="http://www.w3.org/2000/svg"
    xmlns:h="http://www.w3.org/1999/xhtml" xmlns:e="http://exslt.org/common">
  <xsl:output method="xml" indent="yes"/>

  <xsl:template match="clientAnchor">
    <g transform="translate({*/left},{*/top})">
      <rect width="{number(*/right)-number(*/left)}"
        height="{number(*/bottom)-number(*/top)}" fill="green" style="opacity:0.5"/>
      <text y="1em">client</text>
    </g>
  </xsl:template>

  <xsl:template match="childAnchor">
    <g transform="translate({xLeft},{yTop})">
      <rect width="{number(xRight)-number(xLeft)+1}"
            height="{number(yBottom)-number(yTop)+1}" fill="blue" style="opacity:0.5"/>
      <text y="1em">child</text>
    </g>
  </xsl:template>

  <xsl:template name="getX">
    <xsl:choose>
      <xsl:when test="clientAnchor/*/left"><xsl:value-of select="number(clientAnchor/*/left)"/></xsl:when>
      <xsl:otherwise><xsl:value-of select="number(childAnchor/xLeft)"/></xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="getY">
    <xsl:choose>
      <xsl:when test="clientAnchor/*/left"><xsl:value-of select="number(clientAnchor/*/top)"/></xsl:when>
      <xsl:otherwise><xsl:value-of select="number(childAnchor/yTop)"/></xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="getWidth">
    <xsl:choose>
      <xsl:when test="clientAnchor/*/left"><xsl:value-of select="number(clientAnchor/*/right)-number(clientAnchor/*/left)"/></xsl:when>
      <xsl:otherwise><xsl:value-of select="number(childAnchor/xRight)-number(childAnchor/xLeft)"/></xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="getHeight">
    <xsl:choose>
      <xsl:when test="clientAnchor/*/left"><xsl:value-of select="number(clientAnchor/*/bottom)-number(clientAnchor/*/top)"/></xsl:when>
      <xsl:otherwise><xsl:value-of select="number(childAnchor/yBottom)-number(childAnchor/yTop)"/></xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="rgTextCFRun">
    <xsl:if test="cf/masks/bold='true'">font-weight: bold;</xsl:if>
    <xsl:if test="cf/masks/italic='true'">font-style: italic;</xsl:if>
    <xsl:if test="cf/masks/underline='true'">text-decoration:underline;</xsl:if>
  </xsl:template>

  <xsl:template match="*[@type='TextContainer']">
    <xsl:param name="count" select="1"/>
    <xsl:param name="start" select="0"/>
    <xsl:variable name="style">
      <xsl:apply-templates select="style/rgTextCFRun[position()=$count]"/>
    </xsl:variable>
    <xsl:variable name="len" select="style/rgTextCFRun[position()=$count]/count"/>
    <xsl:if test="$count&lt;=count(style/rgTextCFRun)">
      <h:span style="{$style}">
        <xsl:value-of select="substring(text/textChars, $start, $len)"/>
      </h:span>
      <xsl:apply-templates select=".">
        <xsl:with-param name="count" select="$count+1"/>
        <xsl:with-param name="start" select="$start+$len"/>
      </xsl:apply-templates>
    </xsl:if>
  </xsl:template>

  <!-- general shape placeholder -->
  <xsl:template match="*[@type='OfficeArtSpContainer']">
    <xsl:variable name="x"><xsl:call-template name="getX"/></xsl:variable>
    <xsl:variable name="y"><xsl:call-template name="getY"/></xsl:variable>
    <xsl:variable name="w"><xsl:call-template name="getWidth"/></xsl:variable>
    <xsl:variable name="h"><xsl:call-template name="getHeight"/></xsl:variable>
    <xsl:variable name="slideNumber"
        select="count(../../../../../../../preceding-sibling::*/*/*[@type='SlideContainer']/..)+1"/>
    <xsl:variable name="boxNumber" select="count(../preceding-sibling::*)-1"/>
    <g transform="translate({$x}, {$y})">
      <rect width="{$w}" height="{$h}" fill="green" opacity="0.5"/>
      <foreignObject width="{$w}" height="{$h}"><h:body>
        <xsl:apply-templates
          select="//slideList/rgChildRec[position()=$slideNumber]/atoms[position()=$boxNumber]"/>
      </h:body></foreignObject>
    </g>
  </xsl:template>

  <!-- text boxes -->
  <xsl:template match="*[@type='OfficeArtSpContainer'][shapeProp/rh/recInstance=202]">
    <xsl:variable name="x"><xsl:call-template name="getX"/></xsl:variable>
    <xsl:variable name="y"><xsl:call-template name="getY"/></xsl:variable>
    <xsl:variable name="w"><xsl:call-template name="getWidth"/></xsl:variable>
    <xsl:variable name="h"><xsl:call-template name="getHeight"/></xsl:variable>
    <g transform="translate({$x},{$y})">
      <rect width="{$w}" height="{$h}" stroke='black' stroke-width='20' fill='white'/>
      <foreignObject width="{$w}" height="{$h}" >
        <h:body><xsl:apply-templates select=".//*[@type='TextContainer']"/></h:body>
      </foreignObject>
    </g>
  </xsl:template>

  <!-- lines -->
  <xsl:template match="*[@type='OfficeArtSpContainer'][shapeProp/rh/recInstance=20]">
    <xsl:variable name="x"><xsl:call-template name="getX"/></xsl:variable>
    <xsl:variable name="y"><xsl:call-template name="getY"/></xsl:variable>
    <xsl:variable name="w"><xsl:call-template name="getWidth"/></xsl:variable>
    <xsl:variable name="h"><xsl:call-template name="getHeight"/></xsl:variable>
    <line x1="{$x}" y1="{$y}" x2="{$x+$w}" y2="{$y+$h}" stroke-width='20' stroke="black"/>
  </xsl:template>

  <xsl:template match="*[@type='OfficeArtSpgrContainer']">
    <xsl:param name="x" select="rgfb/anon/clientAnchor/*/left"/>
    <xsl:param name="y" select="rgfb/anon/clientAnchor/*/top"/>
    <xsl:param name="width" select="number(rgfb/anon/clientAnchor/*/right)-$x"/>
    <xsl:param name="height" select="number(rgfb/anon/clientAnchor/*/bottom)-$y"/>
    <xsl:param name="vx" select="rgfb/anon/shapeGroup/xLeft"/>
    <xsl:param name="vy" select="rgfb/anon/shapeGroup/yTop"/>
    <xsl:param name="vwidth" select="number(rgfb/anon/shapeGroup/xRight)-$vx"/>
    <xsl:param name="vheight" select="number(rgfb/anon/shapeGroup/yBottom)-$vy"/>
    <xsl:choose>
      <!-- if the first OfficeArtSpContainer has a clientAnchor, a new coordinate system is introduced.
           -->
      <xsl:when test="rgfb[position()=1]/anon/clientAnchor">
        <svg overflow="visible" x="{$x}" y="{$y}" width="{$width}" height="{$height}"
            viewBox="{$vx} {$vy} {$vwidth} {$vheight}">
          <xsl:apply-templates select="rgfb[position()>1]/anon"/>
        </svg>
      </xsl:when>
      <xsl:otherwise>
        <g>
          <xsl:apply-templates select="rgfb[position()>1]/anon"/>
        </g>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <!-- slide container -->
  <xsl:template match="*[@type='SlideContainer']">
    <!-- width and height in inches -->
    <xsl:param name="width" select="//documentAtom/slideSize/x"/>
    <xsl:param name="height" select="//documentAtom/slideSize/y"/>
    <xsl:param name="x" select="'0.5in'"/>
    <xsl:param name="y" select="concat(0.5 + (position()-1)*1.1*$height div 576,'in')"/>
    <svg x="{$x}" y="{$y}" width="{$width div 576.0}in" height="{$height div 576.0}in"
          viewBox="0 0 {$width} {$height}" overflow="visible">
      <!-- slide canvas -->
      <rect width="{$width}" height="{$height}" fill="white" stroke="black" stroke-width="10" />
<!--      <xsl:apply-templates select="drawing/OfficeArtDg/groupShape//clientAnchor"/> -->
      <xsl:apply-templates select="drawing/OfficeArtDg/groupShape"/>
<!--      <xsl:apply-templates select="drawing/OfficeArtDg/shape"/> -->
    </svg>
  </xsl:template>

  <xsl:template match="/">
    <xsl:param name="scale" select="0.4"/>
    <xsl:param name="numSlides"
        select="count(ppt/PowerPointStructs/anon/anon/anon[@type='SlideContainer'])"/>
    <xsl:param name="width" select="//documentAtom/slideSize/x"/>
    <xsl:param name="height" select="//documentAtom/slideSize/y"/>
    <svg width="{100+$scale*(1+$width div 576)}in"
         height="{100+0.5+1.1*$scale*$numSlides*$height div 576}in">
      <text x="10" y="20">Welcome to this presentation</text>
      <g transform="scale({$scale},{$scale})" font-size="300">
        <xsl:apply-templates
          select="ppt/PowerPointStructs/anon/anon/anon[@type='SlideContainer']"/>
      </g>
    </svg>
  </xsl:template>
</xsl:stylesheet>
