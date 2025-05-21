language_specs_install_dir = join_paths(get_option('datadir'),
  'libgedit-gtksourceview-' + LIBGEDIT_GTKSOURCEVIEW_API_VERSION,
  'language-specs')

install_subdir(
  'default-language-specs',
  install_dir: language_specs_install_dir,
  strip_directory: true,
)

install_data(
  'language.dtd',
  'language.rng',
  install_dir: language_specs_install_dir,
)
