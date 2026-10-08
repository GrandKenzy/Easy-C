import gram

if not gram.words.group_exists('types'):
    gram.words.add_group('types')

STANDARD_TYPES = (
    # estandars
    'int', 'char', 'float', 'double', 'void', 'short', 'long',
    'unsigned', 'signed', 'bool',
    # enteros de size fijo
    'uint8_t', 'uint16_t', 'uint32_t', 'uint64_t',
    'int8_t', 'int16_t', 'int32_t', 'int64_t',
    'size_t',
)

for t in STANDARD_TYPES:
    if not gram.words.keyword_exists(t):
        gram.words.add_keyword(t, group='types')
