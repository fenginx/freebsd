# $FreeBSD$

# early setup only see also src.sys.mk

# make sure this is defined in a consistent manner
SRCTOP:= ${.PARSEDIR:tA:H:H}

# site customizations that do not depend on anything!
SRC_ENV_CONF?= /etc/src-env.conf
.if !empty(SRC_ENV_CONF) && !target(_src_env_conf_included_)
.-include "${SRC_ENV_CONF}"
_src_env_conf_included_:	.NOTMAIN
.endif

# If we were found via .../share/mk we need to replace that
# with ${.PARSEDIR:tA} so that we can be found by
# sub-makes launched from objdir.
.if ${.MAKEFLAGS:M.../share/mk} != ""
.MAKEFLAGS:= ${.MAKEFLAGS:S,.../share/mk,${.PARSEDIR:tA},}
.endif
.if ${MAKESYSPATH:Uno:M*.../*} != ""
MAKESYSPATH:= ${MAKESYSPATH:S,.../share/mk,${.PARSEDIR:tA},}
.export MAKESYSPATH
.endif
