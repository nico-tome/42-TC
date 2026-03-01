*This project has been created as part of the 42 curriculum by ntome.*

# Inception (42 project)

## Description

This repository contains the "Inception" project: a multi-service Docker-based deployment used to learn containerization, service orchestration, networking, persistence, and basic service configuration. The goal is to build a small production-like stack (web server, database, CMS, admin tools, and optional bonus services) using Docker and Docker Compose while practicing portability, reproducibility, and secure handling of configuration.

Main services included (locations under `srcs/requirements`):
- `mariadb/` : MariaDB image, custom config and initialization scripts
- `nginx/` : Nginx reverse-proxy configuration
- `wordpress/` : WordPress service and PHP-FPM config
- `redis/` : Redis service (bonus)
- `ftp/` : vsftpd service (bonus)
- `adminer/` : Adminer web DB client (bonus)
- `static_page/` : Simple static HTML page (bonus)

The project uses `docker-compose.yml` (at `srcs/docker-compose.yml`) to define and orchestrate the services. The top-level `Makefile` provides convenient commands to create data directories and bring the stack up or down.

## Project description — Docker usage and included sources

- Orchestration: `srcs/docker-compose.yml` defines the services, networks, volumes, and environment references used to run the stack with `docker compose`.
- Build sources: each service has a directory under `srcs/requirements/` with a `Dockerfile` (when a custom image is required), configuration files in `conf/`, and helper scripts in `tools/` when needed.
- Persistence: service data is persisted under host paths created by the `Makefile` (e.g. `/home/ntome/data/mariadb`, `/home/ntome/data/wordpress`). The Compose file maps volumes so container data remains after container recreation.

Design choices (high level):
- Use Docker Compose for development and local orchestration because it is simple, declarative, and well-suited for the multi-container setup required by the project.
- Keep service configuration in separate `conf/` folders to clearly separate configuration from runtime and to make it easy to bind-mount or build into images.

## Instructions

Prerequisites:
- Docker (20.x+ recommended)
- Docker Compose (v2 plugin or standalone)

Basic commands (from repository root):

```sh
# Build and start the stack in detached mode
make up

# Stop the stack
make down

# Remove created data directories (local host data)
make clean
```

You can also run compose directly:

```sh
docker compose -f srcs/docker-compose.yml up -d --build
```

After startup, services are reachable on the ports defined in `srcs/docker-compose.yml` (see that file for details). The `Makefile` will create persistent data directories under `/home/ntome/data` (adjust the `LOGIN` variable in the `Makefile` if you need a different user path).

Notes on credentials and environment:
- The repository contains `srcs/requirements/.env` which is used for environment variables in Compose. For sensitive production secrets prefer Docker Secrets or a secret manager — see the comparison below.

## Design choices and comparisons

1) Virtual Machines vs Docker
- Virtual Machines (VMs): full OS isolation, strong security boundary, larger disk and RAM overhead, slower startup. Good when you need kernel-level isolation or run multiple OSes.
- Docker (containers): lightweight process-level isolation, much smaller images and faster startup, better resource efficiency and portability for microservices. Containers share the host kernel, so they are less isolated than VMs but well-suited to packaging apps and services.

2) Secrets vs Environment Variables
- Environment variables: convenient for configuration and Compose files but are often visible in process listings, image history, or host files (e.g., `.env`). Not appropriate for highly sensitive secrets in production.
- Docker Secrets: encrypted at rest and only exposed to containers that explicitly request them (works with Docker Swarm and other orchestrators). Use secrets for DB passwords, API keys and other sensitive values; use env files for non-sensitive configuration and simpler local dev.

3) Docker Network vs Host Network
- Default Docker networks (bridge): provide network isolation and predictable service discovery between containers; recommended for multi-container apps and when you want to avoid port collisions and preserve namespace separation.
- Host network: container uses the host network stack directly (no NAT). This removes network isolation and may be useful for performance or when you need services to bind to host network interfaces, but it is less secure and can cause port conflicts.

4) Docker Volumes vs Bind Mounts
- Docker Volumes: managed by Docker, good for production persistence, allow easy backup and migration and do not depend on host paths. Preferred for database storage and production data.
- Bind mounts: directly map host directories into containers. Great for development (hot-reload, editing files on host) or to provide specific config files, but can create portability issues and permission mismatches.

## Resources

- Docker documentation: https://docs.docker.com/
- Docker Compose documentation: https://docs.docker.com/compose/
- Docker volumes vs bind mounts: https://docs.docker.com/storage/
- 42 Network / project resources and subject sheets (refer to your campus materials)
- Useful tutorials and references for this project:
  - "Docker for Developers" tutorials and blog posts
  - Official WordPress + MariaDB with Docker Compose examples

AI assistance
- Parts assisted by AI: README drafting, summarization of Docker design choices and comparisons, and concise instructional wording.
- Tool used: GPT-5 mini (ChatGPT) — used to help structure explanations, generate comparisons (VMs vs containers, secrets vs env, networks, volumes), and to produce the final README text. All code and configuration remained authored and verified locally; AI contributions were limited to editorial and explanatory content.

## Additional notes
- Inspect `srcs/docker-compose.yml` and each service folder under `srcs/requirements/` for exact ports, build args, and environment variable usage.
- Keep secrets out of the repository. If you need to run this stack in a shared or production environment, replace `.env` usage with a secrets manager or Docker Secrets and review file permissions on persistent directories.

---