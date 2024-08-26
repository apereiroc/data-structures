FROM alpine:3.20.2
RUN apk add --no-cache g++ scons
WORKDIR /data-structures
COPY *.cpp *.h SConstruct SConscript .
RUN scons
ENTRYPOINT ["sh", "-c"]
