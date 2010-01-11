SCHEMA=OpenDocument-schema-v1.0-os.rng
STRICTSCHEMA=OpenDocument-strict-schema-v1.0-os.rng
MANIFESTSCHEMA=OpenDocument-manifest-schema-v1.0-os.rng

clean:
	rm -rf *.odp

%.odp: %/content.xml %/styles.xml %/mimetype %/META-INF/manifest.xml
	cd $* && zip -0 -j ../$(@F) mimetype
	cd $* && zip -ru ../$(@F) .
	cd $* && unzip -lv ../$(@F)

%/content.xml: %.xml
	mkdir -p $*
	xsltproc -o $*/c xmltocontent.xsl $<
	xmlstarlet val -e -r $(SCHEMA) $*/c
	xmlstarlet val -e -r $(STRICTSCHEMA) $*/c
	mv $*/c $*/content.xml

%/styles.xml: %.xml
	mkdir -p $*
	xsltproc -o $*/s xmltostyles.xsl $<
	xmlstarlet val -e -r $(SCHEMA) $*/s
	xmlstarlet val -e -r $(STRICTSCHEMA) $*/s
	mv $*/s $*/styles.xml

%/META-INF/manifest.xml: %.xml
	mkdir -p $*/META-INF
	xsltproc -o $*/META-INF/m xmltomanifest.xsl $<
	xmlstarlet val -e -r $(MANIFESTSCHEMA) $*/META-INF/m
	mv $*/META-INF/m $*/META-INF/manifest.xml

%/mimetype: %.xml
	mkdir -p $*
	echo -n "application/vnd.oasis.opendocument.presentation" > $*/mimetype
