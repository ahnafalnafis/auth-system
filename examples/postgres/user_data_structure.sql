/* Example structure for users table */
create table
  if not exists example_users (
    id bigserial not null primary key,
    password varchar(72) not null,
    date_created timestamp not null
  );
