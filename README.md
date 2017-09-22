# drupal_extra
A. DEXTRA merge table
1. To use dextra, create view
CREATE VIEW field_tir_all AS
   SELECT * FROM field_data_field_tir1
   UNION ALL
   SELECT * FROM field_data_field_tir2

2. Change relation ship, in admin UI use this
dextra|table:field_tir_all

New merge table for field
CREATE VIEW field_betting_value_all AS
  SELECT *, GROUP_CONCAT(DISTINCT CONCAT("(", field_betting_value, ")") SEPARATOR '+') as field_betting_value_merged FROM `field_data_field_betting`
  GROUP BY entity_id
