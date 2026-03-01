FROM debian:bookworm

RUN apt update -y && apt upgrade -y && apt install -y mariadb-server mariadb-client gettext-base

EXPOSE 3306
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf


RUN mkdir ./entrypoint-initdb.d
COPY ./tools/init.sql.template /entrypoint-initdb.d
RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld


COPY ./tools/entrypoint.sh ./
RUN chmod +x entrypoint.sh

ENTRYPOINT ["./entrypoint.sh"]
CMD ["mysqld"]