I have added two date null filter and date null contextual argument. Developer can use this to embed a null date argument/filter so the date fields or pager will be show but the query is not affected.
Developers can use this to show other value for the views.

The module enhances the feature of other great contributes modules.
Current enhanced modules are:
- Computed Field, Computed Field Tools
- Field Query
- Views Summarize
- Visitors

The list will be continued.
Mostly are tiny fixes so I can't move it to separate single module.

Once an extra module's fixes is merged to official module, this extra module will be removed out. Please let me know your request if you're one of the author of the module.

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
dextra|converttosingletable:converttosingletable

4. Equal date
dextra|equal:equal

5. Contain date
dextra|contain:contain

6. fieldcompare
Replace the field to compare

7. To reference only the 1st product in commerce relationship use this dextra in the relation ship in the views
dextra|addor:delta:0

New merge table for field
CREATE VIEW field_data_field_betting_all AS
  SELECT *, GROUP_CONCAT(DISTINCT CONCAT("(", field_betting_value, ")") SEPARATOR '+') as field_betting_merged FROM `field_data_field_betting`
  GROUP BY entity_id
OR use this API
drupal_extra_create_field_all_view("field_betting", "value");
