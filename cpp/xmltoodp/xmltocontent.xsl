<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	version="1.0" xmlns:xlink="http://www.w3.org/1999/xlink"
	xmlns:office="urn:oasis:names:tc:opendocument:xmlns:office:1.0"
	xmlns:text="urn:oasis:names:tc:opendocument:xmlns:text:1.0" xmlns:svg="urn:oasis:names:tc:opendocument:xmlns:svg-compatible:1.0"
	xmlns:presentation="urn:oasis:names:tc:opendocument:xmlns:presentation:1.0"
	xmlns:draw="urn:oasis:names:tc:opendocument:xmlns:drawing:1.0" xmlns:h="http://www.w3.org/1999/xhtml">

	<xsl:strip-space elements="*" />
	<xsl:output method="xml" indent="yes" />

	<xsl:template name="getPersistOffset">
		<xsl:param name="persistId" />
		<xsl:param name="userEditAtom" />
		<xsl:variable name="persistDirectoryAtom"
			select="/ppt/PowerPointStructs/anon[@type='PowerPointStruct']/anon[@offset=$userEditAtom/offsetPersistDirectory][@type='PersistDirectoryAtom']" />
		<xsl:variable name="entry"
			select="$persistDirectoryAtom/rgPersistDirEntry[persistId&lt;=$persistId][persistId+cPersist&gt;$persistId]" />
		<xsl:variable name="offset"
			select="$entry/rgPersistOffset[position()=$persistId - ../persistId + 1]/anon" />
		<xsl:choose>
			<!-- the right entry was found -->
			<xsl:when test="$offset">
				<xsl:value-of select="$offset" />
			</xsl:when>
			<!--
				if it was not found there should be and another persistDirectoryAtom
			-->
			<xsl:when test="number($userEditAtom)&gt;0">
				<xsl:call-template name="getPersistOffset">
					<xsl:with-param name="persistId" select="$persistId" />
					<xsl:with-param name="userEditAtom"
						select="PowerPointStructs/anon[@type='PowerPointStruct']/anon[@offset=$userEditAtom/offsetLastEdit][@type='UserEditAtom']" />
				</xsl:call-template>
			</xsl:when>
			<xsl:otherwise>
				<!-- error -->
				<xsl:message terminate="yes">
					No offset was found for persistId
					<xsl:value-of select="$persistId" />
				</xsl:message>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<xsl:template match="/ppt">
		<!-- parsing according to page 26 of [MS-PPT].pdf -->
		<xsl:variable name="currentUserAtom" select="CurrentUserStream/anon1" />
		<!-- get the 'live' (last versions of) the important structures -->
		<xsl:variable name="userEditAtom"
			select="PowerPointStructs/anon[@type='PowerPointStruct']/anon[@offset=$currentUserAtom/offsetToCurrentEdit][@type='UserEditAtom']" />
		<xsl:variable name="documentContainerOffset">
			<xsl:call-template name="getPersistOffset">
				<xsl:with-param name="persistId" select="$userEditAtom/docPersistIdRef" />
				<xsl:with-param name="userEditAtom" select="$userEditAtom" />
			</xsl:call-template>
		</xsl:variable>
		<xsl:variable name="documentContainer"
			select="PowerPointStructs/anon[@type='PowerPointStruct']/anon[@offset=$documentContainerOffset][@type='DocumentContainer']" />
		<!--
			<xsl:message terminate="yes"> hello <xsl:value-of
			select="$documentContainer/slideList/rgChildRec/slidePersistAtom/persistIdRef/anon"/>
			world </xsl:message>
		-->
		<office:document-content>
			<office:body>
				<office:presentation>
					<xsl:for-each
						select="$documentContainer/slideList/rgChildRec/slidePersistAtom">
						<xsl:call-template name="processSlidePersistAtom">
							<xsl:with-param name="documentContainer" select="$documentContainer" />
							<xsl:with-param name="userEditAtom" select="$userEditAtom" />
						</xsl:call-template>
					</xsl:for-each>
				</office:presentation>
			</office:body>
		</office:document-content>
	</xsl:template>

	<xsl:template name="processSlidePersistAtom">
		<xsl:param name="userEditAtom" />
		<xsl:param name="documentContainer" />
		<xsl:variable name="slideContainerOffset">
			<xsl:call-template name="getPersistOffset">
				<xsl:with-param name="persistId" select="persistIdRef/anon" />
				<xsl:with-param name="userEditAtom" select="$userEditAtom" />
			</xsl:call-template>
		</xsl:variable>
		<xsl:variable name="slideContainer"
			select="/ppt/PowerPointStructs/anon[@type='PowerPointStruct']/anon[@type='MasterOrSlideContainer']/anon[@offset=$slideContainerOffset][@type='SlideContainer']" />
		<xsl:variable name="masterName" select="'Default'" />
		<draw:page>
			<xsl:attribute name="draw:master-page-name">
				<xsl:value-of select="$masterName" />
			</xsl:attribute>
			<xsl:apply-templates select="$slideContainer/drawing/OfficeArtDg/groupShape" />
		</draw:page>
	</xsl:template>

	<xsl:template match="*[@type='OfficeArtSpgrContainer']">
		<xsl:param name="x" select="rgfb/anon/clientAnchor/*/left div 576" />
		<xsl:param name="y" select="rgfb/anon/clientAnchor/*/top div 576" />
		<xsl:param name="width"
			select="(number(rgfb/anon/clientAnchor/*/right)-$x) div 576" />
		<xsl:param name="height"
			select="(number(rgfb/anon/clientAnchor/*/bottom)-$y) div 576" />
		<xsl:param name="vx" select="rgfb/anon/shapeGroup/xLeft" />
		<xsl:param name="vy" select="rgfb/anon/shapeGroup/yTop" />
		<xsl:param name="vwidth" select="number(rgfb/anon/shapeGroup/xRight)-$vx" />
		<xsl:param name="vheight" select="number(rgfb/anon/shapeGroup/yBottom)-$vy" />
		<xsl:variable name="scale" select="$vwidth div $width" />
		<xsl:choose>
			<!--
				if the first OfficeArtSpContainer has a clientAnchor, a new
				coordinate system is introduced.
			-->
			<xsl:when test="rgfb[position()=1]/anon/clientAnchor">
				<svg overflow="visible" x="{$x}" y="{$y}" width="{$width}"
					height="{$height}" viewBox="{$vx} {$vy} {$vwidth} {$vheight}"
					font-size="{100*$scale}%">
					<xsl:apply-templates select="rgfb[position()>1]/anon" />
				</svg>
			</xsl:when>
			<xsl:otherwise>
				<xsl:apply-templates select="rgfb[position()>1]/anon" />
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<!--
		<draw:frame draw:layer="layout" svg:x="{$x}in" svg:y="{$y}in"
		svg:width="{$width}in" svg:height="{$height}in"> <draw:text-box>
		<text:p>hello</text:p> </draw:text-box> </draw:frame>
	-->
	<xsl:template match="atoms[@type='TextContainer']">
		<draw:frame draw:layer="layout">
			<xsl:choose>
				<xsl:when test="textHeaderAtom/textType=0">
					<xsl:attribute name="presentation:class">title</xsl:attribute>
				</xsl:when>
			</xsl:choose>
			<draw:text-box>
				<text:p>
					<xsl:value-of select="text/textChars" />
				</text:p>
			</draw:text-box>
		</draw:frame>
	</xsl:template>

</xsl:stylesheet>
