# User Documentation

## Overview — services provided

This stack provides a small multi-service environment built with Docker Compose. The main services included are:
- `mariadb` — relational database used by WordPress.
- `nginx` — HTTP reverse proxy / web server.
- `wordpress` — WordPress application (PHP + PHP-FPM).
- `adminer` (bonus) — web-based database administration tool.
- `redis` (bonus) — optional in-memory store for caching.
- `ftp` (bonus) — FTP service for file uploads (if included).
- `static_page` (bonus) — a simple static HTML site.

Exact service names, ports and additional options are defined in `srcs/docker-compose.yml` and per-service folders under `srcs/requirements/`.

## Start and stop the project

From the repository root you can use the provided `Makefile`:

```sh
# Start (build + run in background)
make up

# Stop containers
make down

# Remove created host data directories
make clean
```

Alternatively, run Compose directly:

```sh
docker compose -f srcs/docker-compose.yml up -d --build
docker compose -f srcs/docker-compose.yml down
```

## Accessing the website and administration panel

- Website: open your browser to the host and port mapped to the `nginx` or `wordpress` service as defined in `srcs/docker-compose.yml` (for example, `http://localhost:<port>`). If `nginx` is configured as a reverse proxy, use its host port.
- WordPress admin: visit `http://<site-host>:<port>/wp-admin` and log in with the WordPress admin account created during setup (see credentials below).
- Adminer: visit the port mapped to the `adminer` service (see `srcs/docker-compose.yml`) to access a web-based DB client.

If you are unsure of ports, run:

```sh
docker compose -f srcs/docker-compose.yml ps
```

## Credentials — locate and manage

- Environment variables used by the Compose setup are stored in `srcs/requirements/.env`.
- The `Makefile` creates persistent host directories under `/home/$(LOGIN)/data` (see `Makefile` and adjust `LOGIN` if required). Database files and WordPress uploads are persisted in those directories.

Best practices for credentials:
- Do not commit secrets into the repository. Keep `srcs/requirements/.env` out of public version control or replace its usage with Docker Secrets or a secrets manager for production.
- To change credentials, edit `srcs/requirements/.env`, then recreate affected services:

```sh
docker compose -f srcs/docker-compose.yml up -d --force-recreate --build
```

## Checking services are running

- List containers and their state:

```sh
docker compose -f srcs/docker-compose.yml ps
docker ps --filter "label=com.docker.compose.project"
```

- View logs for a specific service:

```sh
docker compose -f srcs/docker-compose.yml logs -f <service_name>
```

- Health checks: if services expose health checks in `docker-compose.yml`, you can inspect them with `docker inspect --format='{{json .State.Health}}' <container>`.

## Troubleshooting tips
- If WordPress cannot connect to the database, verify DB credentials in `srcs/requirements/.env` and that `mariadb` is running.
- File permission issues for persisted data can be fixed by adjusting owner/group on the host persistent directories (e.g., `/home/$(LOGIN)/data/...`).
- Use `docker-compose logs` and `docker-compose exec` to inspect runtime state and interact with containers.

---
For other details about structure and developer setup, see `DEV_DOC.md`.
