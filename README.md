# drupal_extra
A. DEXTRA merge table
1. To use dextra, create view
CREATE VIEW field_tir_all AS
   SELECT * FROM field_data_field_tir1
   UNION ALL
   SELECT * FROM field_data_field_tir2

2. Change relation ship, in admin UI use this
dextra|table:field_tir_all

3. More join
dextra|morejoin:morejoin

4. Equal date
dextra|equal:equal

5. Contain date
dextra|contain:contain

6. fieldcompare
Replace the field to compare

New merge table for field
CREATE VIEW field_data_field_betting_all AS
  SELECT *, GROUP_CONCAT(DISTINCT CONCAT("(", field_betting_value, ")") SEPARATOR '+') as field_betting_merged FROM `field_data_field_betting`
  GROUP BY entity_id
OR use this API
drupal_extra_create_field_all_view("field_betting", "value");
