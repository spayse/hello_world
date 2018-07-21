package=expat
$(package)_version=2.2.3
$(package)_download_path=https://downloads.sourceforge.net/project/expat/expat/$($(package)_version)
$(package)_file_name=$(package)-$($(package)_version).tar.bz2
$(package)_sha256_hash=b31890fb02f85c002a67491923f89bda5028a880fd6c374f707193ad81aace5f

define $(package)_set_vars
$(package)_config_opts=--disable-static
endef

define $(package)_config_cmds
  $($(package)_autoconf)
endef

define $(package)_build_cmds
  $(MAKE)
endef

define $(package)_stage_cmds
  $(MAKE) DESTDIR=$($(package)_staging_dir) install
endef
