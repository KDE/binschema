<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
    xmlns:xlink="http://www.w3.org/1999/xlink" xmlns="http://www.w3.org/2000/svg"
    xmlns:h="http://www.w3.org/1999/xhtml">
  <xsl:output method="xml" indent="no"/>

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
      <xsl:when test="clientAnchor/*/left"><xsl:value-of
        select="number(clientAnchor/*/left)"/></xsl:when>
      <xsl:otherwise><xsl:value-of select="number(childAnchor/xLeft)"/></xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="getY">
    <xsl:choose>
      <xsl:when test="clientAnchor/*/left"><xsl:value-of
        select="number(clientAnchor/*/top)"/></xsl:when>
      <xsl:otherwise><xsl:value-of select="number(childAnchor/yTop)"/></xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="getWidth">
    <xsl:choose>
      <xsl:when test="clientAnchor/*/left"><xsl:value-of
        select="number(clientAnchor/*/right)-number(clientAnchor/*/left)"/></xsl:when>
      <xsl:otherwise><xsl:value-of
        select="number(childAnchor/xRight)-number(childAnchor/xLeft)"/></xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="getHeight">
    <xsl:choose>
      <xsl:when test="clientAnchor/*/left"><xsl:value-of
        select="number(clientAnchor/*/bottom)-number(clientAnchor/*/top)"/></xsl:when>
      <xsl:otherwise><xsl:value-of
        select="number(childAnchor/yBottom)-number(childAnchor/yTop)"/></xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="getY1">
    <xsl:variable name="y"><xsl:call-template name="getY"/></xsl:variable>
    <xsl:variable name="h"><xsl:call-template name="getHeight"/></xsl:variable>
    <xsl:choose>
      <xsl:when test="shapeProp/fFlipV='true'"><xsl:value-of select="$y+$h"/></xsl:when>
      <xsl:otherwise><xsl:value-of select="$y"/></xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="getY2">
    <xsl:variable name="y"><xsl:call-template name="getY"/></xsl:variable>
    <xsl:variable name="h"><xsl:call-template name="getHeight"/></xsl:variable>
    <xsl:choose>
      <xsl:when test="shapeProp/fFlipV='true'"><xsl:value-of select="$y"/></xsl:when>
      <xsl:otherwise><xsl:value-of select="$y+$h"/></xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="getMasterId">
    <xsl:if test="slideAtom/masterIdRef"><xsl:value-of select="slideAtom/masterIdRef"/></xsl:if>
    <xsl:for-each select="..">
      <xsl:call-template name="getMasterId"/>
    </xsl:for-each>
  </xsl:template>

  <xsl:template match="*[@type='OfficeArtCOLORREF']" name="getColor">
    <xsl:value-of select="concat('rgb(',red,',',green,',',blue,')')"/>
  </xsl:template>

  <xsl:template name="getSpacing">
    <xsl:choose>
      <xsl:when test=".&lt;0"><xsl:value-of select="-node()"/></xsl:when>
      <xsl:when test=".&lt;=13200"><xsl:value-of select="node()"/>ex</xsl:when>
      <xsl:otherwise>0</xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:variable name="hexDigits" select="'0123456789ABCDEF'" />
  <xsl:template name="toHex">
    <xsl:param name="decimalNumber" />
    <xsl:if test="$decimalNumber >= 16">
      <xsl:call-template name="toHex">
        <xsl:with-param name="decimalNumber" select="floor($decimalNumber div 16)" />
      </xsl:call-template>
    </xsl:if>
    <xsl:value-of select="substring($hexDigits, ($decimalNumber mod 16) + 1, 1)" />
  </xsl:template>

  <xsl:template match="pf[@type='TextPFException']">
    <xsl:if test="masks/wordWrap='false'">white-space: pre-wrap;</xsl:if><!-- or 'pre'? -->
    <xsl:if test="textAlignment='0'">text-align: left;</xsl:if>
    <xsl:if test="textAlignment='1'">text-align: center;</xsl:if>
    <xsl:if test="textAlignment='2'">text-align: right;</xsl:if>
    <xsl:if test="textAlignment='3'">text-align: justify;</xsl:if>
    <!-- todo: figure out the right units here -->
    <xsl:if test="indent">margin-left: <xsl:value-of select="indent"/>pt;</xsl:if>
  </xsl:template>

  <xsl:template name="PFBefore">
  </xsl:template>

  <xsl:template name="PFBulletBefore">
    <xsl:variable name="char">
      <xsl:call-template name="toHex">
        <xsl:with-param name="decimalNumber" select="bulletChar"/>
      </xsl:call-template>
    </xsl:variable>
    <xsl:call-template name="PFBefore"/>
    <xsl:if test="bulletChar">content: '\<xsl:value-of select="$char"/>';</xsl:if>
  </xsl:template>

  <xsl:template match="cf[@type='TextCFException']">
    <xsl:if test="masks/bold='true'">font-weight: bold;</xsl:if>
    <xsl:if test="masks/italic='true'">font-style: italic;</xsl:if>
    <xsl:if test="masks/underline='true'">text-decoration: underline;</xsl:if>
    <xsl:if test="fontSize">font-size: <xsl:value-of select="fontSize*10 div 12"/>%;</xsl:if>
    <xsl:apply-templates select="ansiFontRef"/>
    <xsl:apply-templates select="fontRef"/>
  </xsl:template>

  <xsl:template match="lfFaceName">
    <xsl:value-of select="concat('font-family:',substring-before(node(),'%'),';')"/>
  </xsl:template>

  <xsl:template match="ansiFontRef|fontRef">
    <xsl:choose>
      <xsl:when test="node()&lt;count(//rgFontCollectionEntry)">
        <xsl:apply-templates
          select="//rgFontCollectionEntry[position()=node()]/fontEntityAtom/lfFaceName"/>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-templates select="//rgFontCollectionEntry[position()=1]/fontEntityAtom/lfFaceName"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="CFRun">
    <xsl:param name="offset"/>
    <xsl:param name="text"/>
    <xsl:param name="ccount" select="1"/>
    <xsl:param name="start" select="1"/>
    <xsl:variable name="style">
      <xsl:apply-templates select="style/rgTextCFRun[position()=$ccount]/cf"/>
    </xsl:variable>
    <xsl:variable name="len" select="style/rgTextCFRun[position()=$ccount]/count"/>
    <xsl:variable name="subtext" select="substring($text, $start - $offset+1, $len)"/>

    <!-- loop over all CFRun elements -->
    <xsl:if test="$ccount&lt;=count(style/rgTextCFRun)">
      <xsl:if test="string-length($subtext)">
        <h:span>
          <xsl:value-of select="$subtext"/>
        </h:span>
      </xsl:if>
      <xsl:call-template name="CFRun">
        <xsl:with-param name="offset" select="$offset"/>
        <xsl:with-param name="text" select="$text"/>
        <xsl:with-param name="ccount" select="$ccount+1"/>
        <xsl:with-param name="start" select="$start+$len"/>
      </xsl:call-template>
    </xsl:if>
  </xsl:template>

  <xsl:template name="getClass">
    <xsl:param name="indent" />
    <xsl:variable name="type" select="textHeaderAtom/textType"/>
    <xsl:variable name="class" select="concat('texttype', $type, 'lstLvl',($indent+1))"/>
    <xsl:choose>
      <xsl:when test="bulletFlags/fHasBullet='false'">
        <xsl:value-of select="$class"/>
      </xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="concat($class, ' ', $class, 'Bullet')"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="getBullet">
    <!-- very simple for now, we just write 'O'. this needs to be expanded to get either the defined
         bullet character or the inherited bullet character -->
    <xsl:variable name="char">
      <xsl:call-template name="toHex">
        <xsl:with-param name="decimalNumber" select="bulletChar"/>
      </xsl:call-template>
    </xsl:variable>
    <xsl:if test="bulletFlags/fHasBullet='true'">O </xsl:if>
  </xsl:template>

  <xsl:template match="*[@type='TextContainer']">
    <xsl:param name="pcount" select="1"/>
    <xsl:param name="start" select="1"/>
    <xsl:variable name="indent" select="style/rgTextPFRun[position()=$pcount]/indentLevel"/>
    <xsl:variable name="type" select="textHeaderAtom/textType"/>
    <xsl:variable name="class" select="concat('texttype', $type, 'lstLvl', ($indent+1))"/>
    <xsl:variable name="style">
      <xsl:apply-templates select="style/rgTextPFRun[position()=$pcount]/pf"/>
    </xsl:variable>
    <xsl:variable name="len" select="style/rgTextPFRun[position()=$pcount]/count"/>
    <xsl:variable name="text" select="substring(text/textChars, $start, $len)"/>

    <xsl:if test="$pcount&lt;=count(style/rgTextPFRun)">
      <xsl:if test="string-length($text)">
        <h:p style="{$style}" class="{$class}">
          <!-- bullet is put in the text, using css is too hard -->
          <xsl:for-each select="style/rgTextPFRun[position()=$pcount]/pf">
            <xsl:call-template name="getBullet">
              <xsl:with-param name="indent" select="indent"/>
            </xsl:call-template>
          </xsl:for-each>
          <xsl:call-template name="CFRun">
            <xsl:with-param name="offset" select="$start"/>
            <xsl:with-param name="text" select="$text"/>
          </xsl:call-template>
        </h:p>
      </xsl:if>
      <xsl:apply-templates select=".">
        <xsl:with-param name="pcount" select="$pcount+1"/>
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
          select="//anon[anon/slideList][last()]/anon/slideList/rgChildRec[position()=$slideNumber]/atoms[position()=$boxNumber]"/>
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
    <xsl:variable name="y1"><xsl:call-template name="getY1"/></xsl:variable>
    <xsl:variable name="y2"><xsl:call-template name="getY2"/></xsl:variable>
    <xsl:variable name="start"
        select="shapePrimaryOptions/fopt/anon[@type='LineStartArrowhead']/lineStartArrowhead='1'"/>
    <xsl:variable name="end"
        select="shapePrimaryOptions/fopt/anon[@type='LineEndArrowhead']/lineEndArrowhead='1'"/>
    <g stroke-width='20'>
      <xsl:if test="shapePrimaryOptions/fopt/anon/lineColor">
        <xsl:attribute name="stroke"><xsl:apply-templates select="shapePrimaryOptions/fopt/anon/lineColor"/></xsl:attribute>
        <xsl:attribute name="fill"><xsl:apply-templates select="shapePrimaryOptions/fopt/anon/lineColor"/></xsl:attribute>
      </xsl:if>
      <line x1="{$x}" y1="{$y1}" x2="{$x+$w}" y2="{$y2}">
        <xsl:if test="$start">
          <xsl:attribute name="marker-start">url(#msArrowStart_20_5)</xsl:attribute>
        </xsl:if>
        <xsl:if test="$end">
          <xsl:attribute name="marker-end">url(#msArrowEnd_20_5)</xsl:attribute>
        </xsl:if>
      </line>
    </g>
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
      <xsl:apply-templates select="drawing/OfficeArtDg/groupShape"/>
    </svg>
  </xsl:template>

  <xsl:template match="*[@type='TextMasterStyleAtom']">
    <xsl:param name="prefix"/>
    .<xsl:value-of select="$prefix"/>lstLvl1 {
      <xsl:apply-templates select="lstLvl1/pf"/>
      <xsl:apply-templates select="lstLvl1/cf"/>
    }
    .<xsl:value-of select="$prefix"/>lstLvl1:before {
      <xsl:for-each select="lstLvl1/pf">
        <xsl:call-template name="PFBefore"/>
      </xsl:for-each>
    }
    .<xsl:value-of select="$prefix"/>lstLvl1Bullet:before {
      <xsl:for-each select="lstLvl1/pf">
        <xsl:call-template name="PFBulletBefore"/>
      </xsl:for-each>
    }
    .<xsl:value-of select="$prefix"/>lstLvl2 {
      <xsl:apply-templates select="lstLvl2/pf"/>
      <xsl:apply-templates select="lstLvl2/cf"/>
    }
    .<xsl:value-of select="$prefix"/>lstLvl2:before {
      <xsl:for-each select="lstLvl2/pf">
        <xsl:call-template name="PFBefore"/>
      </xsl:for-each>
    }
    .<xsl:value-of select="$prefix"/>lstLvl3 {
      <xsl:apply-templates select="lstLvl3/pf"/>
      <xsl:apply-templates select="lstLvl3/cf"/>
    }
    .<xsl:value-of select="$prefix"/>lstLvl3:before {
      <xsl:for-each select="lstLvl3/pf">
        <xsl:call-template name="PFBefore"/>
      </xsl:for-each>
    }
    .<xsl:value-of select="$prefix"/>lstLvl4 {
      <xsl:apply-templates select="lstLvl4/pf"/>
      <xsl:apply-templates select="lstLvl4/cf"/>
    }
    .<xsl:value-of select="$prefix"/>lstLvl4:before {
      <xsl:for-each select="lstLvl4/pf">
        <xsl:call-template name="PFBefore"/>
      </xsl:for-each>
    }
    .<xsl:value-of select="$prefix"/>lstLvl5 {
      <xsl:apply-templates select="lstLvl5/pf"/>
      <xsl:apply-templates select="lstLvl5/cf"/>
    }
    .<xsl:value-of select="$prefix"/>lstLvl5:before {
      <xsl:for-each select="lstLvl5/pf">
        <xsl:call-template name="PFBefore"/>
      </xsl:for-each>
    }
  </xsl:template>

  <xsl:template match="/">
    <xsl:param name="scale" select="0.4"/>
    <xsl:param name="numSlides"
        select="count(ppt/PowerPointStructs/anon/anon/anon[@type='SlideContainer'])"/>
    <xsl:param name="width" select="//documentAtom/slideSize/x"/>
    <xsl:param name="height" select="//documentAtom/slideSize/y"/>
    <xsl:variable name="pstyle">
      <xsl:apply-templates select="//textPFDefaultsAtom/pf"/>
    </xsl:variable>
    <xsl:variable name="cstyle">
      <xsl:apply-templates select="//textCFDefaultsAtom/cf"/>
    </xsl:variable>
    <svg width="{100+$scale*(1+$width div 576)}in"
         height="{100+0.5+1.1*$scale*$numSlides*$height div 576}in"
         stroke="black" fill="black" style="{$pstyle}{$cstyle}">
      <defs>
        <style type="text/css">
          <xsl:apply-templates select="//textMasterStyleAtom"/>
          <xsl:for-each select="//rgTextMasterStyle">
            <xsl:apply-templates select=".">
              <xsl:with-param name="prefix" select="concat('texttype',position()-1)"/>
            </xsl:apply-templates>
          </xsl:for-each>
        </style>
        <marker id="msArrowStart_20_5" viewBox="0 0 10 10" refX="0" refY="5" 
            markerUnits="strokeWidth" markerWidth="20" markerHeight="8" orient="auto">
          <path d="M 10 0 L 0 5 L 10 10 z" />
        </marker>
        <marker id="msArrowEnd_20_5" viewBox="0 0 10 10" refX="10" refY="5" 
            markerUnits="strokeWidth" markerWidth="20" markerHeight="8" orient="auto">
          <path d="M 0 0 L 10 5 L 0 10 z" />
        </marker>
      </defs>
      <text x="10" y="20">Welcome to this presentation</text>
      <g transform="scale({$scale},{$scale})" font-size="300">
        <xsl:apply-templates
          select="ppt/PowerPointStructs/anon/anon/anon[@type='SlideContainer']"/>
      </g>
    </svg>
  </xsl:template>
</xsl:stylesheet>
