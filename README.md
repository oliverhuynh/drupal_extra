# drupal_extra
A. DEXTRA merge table
1. To use dextra, create view
CREATE VIEW field_tir_all AS
   SELECT * FROM field_data_field_tir1
   UNION ALL
   SELECT * FROM field_data_field_tir2

2. Change relation ship, in admin UI use this
dextra|table:field_tir_all
