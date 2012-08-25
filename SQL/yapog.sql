--
-- PostgreSQL database dump
--

-- Dumped from database version 9.1.4
-- Dumped by pg_dump version 9.1.4
-- Started on 2012-08-25 16:49:39

SET statement_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

--
-- TOC entry 169 (class 3079 OID 11639)
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- TOC entry 1897 (class 0 OID 0)
-- Dependencies: 169
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = public, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- TOC entry 161 (class 1259 OID 16978)
-- Dependencies: 6
-- Name: account; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE account (
    account_id integer NOT NULL,
    account_name character varying(15) NOT NULL,
    account_password character(32) NOT NULL,
    account_email character varying(60) NOT NULL,
    account_permissions smallint NOT NULL,
    account_creation_date timestamp without time zone NOT NULL,
    account_last_login_date timestamp without time zone NOT NULL,
    account_creation_ip inet NOT NULL,
    account_current_ip inet
);


ALTER TABLE public.account OWNER TO postgres;

--
-- TOC entry 162 (class 1259 OID 16984)
-- Dependencies: 6 161
-- Name: account_account_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE account_account_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.account_account_id_seq OWNER TO postgres;

--
-- TOC entry 1898 (class 0 OID 0)
-- Dependencies: 162
-- Name: account_account_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE account_account_id_seq OWNED BY account.account_id;


--
-- TOC entry 163 (class 1259 OID 16986)
-- Dependencies: 6
-- Name: player_data; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE player_data (
    account_id integer NOT NULL,
    player_data_position point,
    player_data_time integer,
    player_data_step_count integer,
    player_data_respawn_spot point,
    player_data_flee_count integer,
    player_data_box_number integer,
    player_data_battle_count integer,
    player_data_money integer,
    player_data_map_id integer
);


ALTER TABLE public.player_data OWNER TO postgres;

--
-- TOC entry 164 (class 1259 OID 16989)
-- Dependencies: 6
-- Name: pokemon; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE pokemon (
    account_id integer NOT NULL,
    pokemon_id integer NOT NULL,
    pokemon_static_id integer NOT NULL,
    pokemon_experience integer NOT NULL,
    pokemon_gender integer NOT NULL,
    pokemon_nickname character varying(10),
    pokemon_shiny boolean NOT NULL,
    pokemon_loyalty integer NOT NULL,
    pokemon_nature integer NOT NULL,
    pokemon_trading_number integer NOT NULL,
    pokemon_trader_account_id integer,
    pokemon_box_number integer NOT NULL,
    pokemon_box_index integer NOT NULL,
    pokemon_catch_date timestamp without time zone,
    pokemon_status integer NOT NULL
);


ALTER TABLE public.pokemon OWNER TO postgres;

--
-- TOC entry 165 (class 1259 OID 16992)
-- Dependencies: 6
-- Name: pokemon_ev; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE pokemon_ev (
    pokemon_id integer NOT NULL,
    pokemon_ev_attack integer NOT NULL,
    pokemon_ev_defense integer NOT NULL,
    pokemon_ev_special_attack integer NOT NULL,
    pokemon_ev_special_defense integer NOT NULL,
    pokemon_ev_speed integer NOT NULL,
    pokemon_ev_hp integer NOT NULL
);


ALTER TABLE public.pokemon_ev OWNER TO postgres;

--
-- TOC entry 166 (class 1259 OID 16995)
-- Dependencies: 6
-- Name: pokemon_move; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE pokemon_move (
    pokemon_move_index integer NOT NULL,
    pokemon_id integer NOT NULL,
    pokemon_move_static_id integer NOT NULL,
    pokemon_move_pp integer NOT NULL,
    pokemon_move_max_pp integer NOT NULL
);


ALTER TABLE public.pokemon_move OWNER TO postgres;

--
-- TOC entry 167 (class 1259 OID 16998)
-- Dependencies: 164 6
-- Name: pokemon_pokemon_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE pokemon_pokemon_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.pokemon_pokemon_id_seq OWNER TO postgres;

--
-- TOC entry 1899 (class 0 OID 0)
-- Dependencies: 167
-- Name: pokemon_pokemon_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE pokemon_pokemon_id_seq OWNED BY pokemon.pokemon_id;


--
-- TOC entry 168 (class 1259 OID 17000)
-- Dependencies: 6
-- Name: pokemon_stats; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE pokemon_stats (
    pokemon_id integer NOT NULL,
    pokemon_stats_attack integer NOT NULL,
    pokemon_stats_defense integer NOT NULL,
    pokemon_stats_special_attack integer NOT NULL,
    pokemon_stats_special_defense integer NOT NULL,
    pokemon_stats_speed integer NOT NULL,
    pokemon_stats_hp integer NOT NULL,
    pokemon_stats_max_hp integer NOT NULL
);


ALTER TABLE public.pokemon_stats OWNER TO postgres;

--
-- TOC entry 1871 (class 2604 OID 17003)
-- Dependencies: 162 161
-- Name: account_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY account ALTER COLUMN account_id SET DEFAULT nextval('account_account_id_seq'::regclass);


--
-- TOC entry 1872 (class 2604 OID 17004)
-- Dependencies: 167 164
-- Name: pokemon_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY pokemon ALTER COLUMN pokemon_id SET DEFAULT nextval('pokemon_pokemon_id_seq'::regclass);


--
-- TOC entry 1875 (class 2606 OID 17006)
-- Dependencies: 161 161
-- Name: account_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY account
    ADD CONSTRAINT account_pkey PRIMARY KEY (account_id);


--
-- TOC entry 1877 (class 2606 OID 17008)
-- Dependencies: 163 163
-- Name: player_data_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY player_data
    ADD CONSTRAINT player_data_pkey PRIMARY KEY (account_id);


--
-- TOC entry 1882 (class 2606 OID 17010)
-- Dependencies: 165 165
-- Name: pokemon_ev_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY pokemon_ev
    ADD CONSTRAINT pokemon_ev_pkey PRIMARY KEY (pokemon_id);


--
-- TOC entry 1884 (class 2606 OID 17012)
-- Dependencies: 166 166 166
-- Name: pokemon_move_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY pokemon_move
    ADD CONSTRAINT pokemon_move_pkey PRIMARY KEY (pokemon_move_index, pokemon_id);


--
-- TOC entry 1880 (class 2606 OID 17014)
-- Dependencies: 164 164
-- Name: pokemon_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY pokemon
    ADD CONSTRAINT pokemon_pkey PRIMARY KEY (pokemon_id);


--
-- TOC entry 1886 (class 2606 OID 17016)
-- Dependencies: 168 168
-- Name: pokemon_stats_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY pokemon_stats
    ADD CONSTRAINT pokemon_stats_pkey PRIMARY KEY (pokemon_id);


--
-- TOC entry 1873 (class 1259 OID 17017)
-- Dependencies: 161 161
-- Name: account_account_name_unique_index; Type: INDEX; Schema: public; Owner: postgres; Tablespace: 
--

CREATE UNIQUE INDEX account_account_name_unique_index ON account USING btree (lower((account_name)::text));


--
-- TOC entry 1878 (class 1259 OID 17018)
-- Dependencies: 164
-- Name: fki_pokemon_account_id_fkey; Type: INDEX; Schema: public; Owner: postgres; Tablespace: 
--

CREATE INDEX fki_pokemon_account_id_fkey ON pokemon USING btree (account_id);


--
-- TOC entry 1887 (class 2606 OID 17019)
-- Dependencies: 1874 163 161
-- Name: player_data_account_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY player_data
    ADD CONSTRAINT player_data_account_id_fkey FOREIGN KEY (account_id) REFERENCES account(account_id);


--
-- TOC entry 1888 (class 2606 OID 17024)
-- Dependencies: 164 1874 161
-- Name: pokemon_account_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY pokemon
    ADD CONSTRAINT pokemon_account_id_fkey FOREIGN KEY (account_id) REFERENCES account(account_id);


--
-- TOC entry 1889 (class 2606 OID 17029)
-- Dependencies: 164 165 1879
-- Name: pokemon_ev_pokemon_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY pokemon_ev
    ADD CONSTRAINT pokemon_ev_pokemon_id_fkey FOREIGN KEY (pokemon_id) REFERENCES pokemon(pokemon_id);


--
-- TOC entry 1890 (class 2606 OID 17034)
-- Dependencies: 166 1879 164
-- Name: pokemon_move_pokemon_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY pokemon_move
    ADD CONSTRAINT pokemon_move_pokemon_id_fkey FOREIGN KEY (pokemon_id) REFERENCES pokemon(pokemon_id);


--
-- TOC entry 1891 (class 2606 OID 17039)
-- Dependencies: 164 168 1879
-- Name: pokemon_stats_pokemon_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY pokemon_stats
    ADD CONSTRAINT pokemon_stats_pokemon_id_fkey FOREIGN KEY (pokemon_id) REFERENCES pokemon(pokemon_id);


--
-- TOC entry 1896 (class 0 OID 0)
-- Dependencies: 6
-- Name: public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


-- Completed on 2012-08-25 16:49:40

--
-- PostgreSQL database dump complete
--

