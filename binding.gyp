{
  'targets': [
    {
      'target_name': 'callback',
      'sources': [
        './src/callback.cc',
      ],
      'include_dirs': [
        '<!(node -e "require(\'nan\')")',
      ]
    }
  ]
}
