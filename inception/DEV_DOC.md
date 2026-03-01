# Developer Documentation

## Prerequisites

- Install Docker (engine) and the Docker Compose plugin or standalone Compose.
- Install `make`.
- Ensure your user can run Docker commands (add to `docker` group or use `sudo`).

## Repository layout (important files)

- `Makefile` — convenience targets to create local data directories and run Compose.
- `srcs/docker-compose.yml` — service definitions, networks, volumes and environment references.
- `srcs/requirements/.env` — environment variables used by Compose (local configs, DB credentials, etc.).
- `srcs/requirements/<service>/` — per-service Dockerfiles, `conf/` and `tools/` folders.

## Setup from scratch

1. Clone the repository.
2. Inspect `srcs/requirements/.env` and update values as needed. Do NOT commit secrets.
3. (Optional) Adjust `LOGIN` in the `Makefile` if you want host data in a different path.

Commands to prepare and launch:

```sh
# From repository root
make up

# or with docker compose directly
docker compose -f srcs/docker-compose.yml up -d --build
```

The `Makefile` creates persistent directories under `/home/$(LOGIN)/data` for services that require host storage.

## Building images and services

- To rebuild a single service image defined with a `Dockerfile`:

```sh
docker compose -f srcs/docker-compose.yml build <service_name>
docker compose -f srcs/docker-compose.yml up -d <service_name>
```

- To force-recreate containers after configuration changes:

```sh
docker compose -f srcs/docker-compose.yml up -d --force-recreate --build
```

## Managing containers and volumes

- List running containers for the project:

```sh
docker compose -f srcs/docker-compose.yml ps
```

- Follow logs for a service:

```sh
docker compose -f srcs/docker-compose.yml logs -f <service_name>
```

- Stop and remove containers (keeping volumes):

```sh
docker compose -f srcs/docker-compose.yml down
```

- Stop and remove containers and anonymous volumes:

```sh
docker compose -f srcs/docker-compose.yml down --volumes
```

- List Docker volumes and remove unused ones:

```sh
docker volume ls
docker volume rm <volume_name>
docker system prune -f --volumes
```

## Data storage and persistence

- Host persistent directories: the `Makefile` creates `/home/$(LOGIN)/data` and subfolders such as `/home/$(LOGIN)/data/mariadb` and `/home/$(LOGIN)/data/wordpress`. These folders are used as bind mounts by the Compose file for persistent storage.
- Docker volumes: some services may use named Docker volumes declared in `srcs/docker-compose.yml` — inspect that file for exact names and usage. Named volumes are managed by Docker and are independent of host paths.

Persistence behaviour:
- Database data (MariaDB) is persisted to the host path created by the `Makefile` or to a Docker-managed volume depending on `docker-compose.yml`.
- WordPress uploads and other service data are persisted similarly; check service volume mappings in `srcs/docker-compose.yml`.

## Configuration and secrets

- `srcs/requirements/.env` contains configuration values for Compose. For production use, prefer Docker Secrets or an external secrets manager instead of env files.
- To convert env values to Docker Secrets (Swarm or other orchestrators), create secrets and reference them in the Compose file. Test locally with a secure method of providing secrets.

## Development tips

- When developing service configuration (e.g., `nginx/conf/nginx.conf`), prefer bind-mounting local config for fast iteration, then bake the config into the image for production.
- Use `docker compose exec <service> /bin/sh` (or `/bin/bash`) to run commands inside containers for debugging.
- When changing DB initialization SQL in `srcs/requirements/mariadb/tools/init.sql.template`, be aware initialization scripts typically only run on first container start if an empty DB directory/volume is present.

## Where to look next

- `srcs/docker-compose.yml` — confirm ports, networks, volumes and service names.
- Per-service folders under `srcs/requirements/` — read `Dockerfile`, `conf/`, and `tools/` for service-specific behaviour.

---
If you want, I can also generate a small script to create example secrets and demonstrate replacing `.env` with Docker Secrets for local testing.
