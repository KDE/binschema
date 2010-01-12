<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	version="1.0" xmlns:manifest="urn:oasis:names:tc:opendocument:xmlns:manifest:1.0">

	<xsl:output method="xml" indent="yes" />

	<xsl:template match="/">
		<manifest:manifest>
			<manifest:file-entry
				manifest:media-type="application/vnd.oasis.opendocument.presentation"
				manifest:full-path="/" />
			<manifest:file-entry manifest:media-type="text/xml"
				manifest:full-path="content.xml" />
			<manifest:file-entry manifest:media-type="text/xml"
				manifest:full-path="styles.xml" />
		</manifest:manifest>
	</xsl:template>

</xsl:stylesheet>
