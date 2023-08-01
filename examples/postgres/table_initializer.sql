/* Example structure for users table */
create table
  if not exists mock_users (
    id bigserial not null primary key,
    email varchar(50) not null unique,
    password varchar(72) not null,
    date_created timestamp not null
  );
