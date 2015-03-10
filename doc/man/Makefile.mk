uninstall-man : uninstall-man-local

uninstall-man-local :
	${AM_V_at} for f in ${l10n_man}; do \
	  LINGUA=$$(echo $$f | $(SED) 's/ccd2cue\.\(.*\)\.1/\1/'); \
	  $(RM) -f ${DESTDIR}${mandir}/$${LINGUA}.UTF-8/man1/ccd2cue.1; done;
