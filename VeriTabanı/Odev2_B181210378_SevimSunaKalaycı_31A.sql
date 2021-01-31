--
-- PostgreSQL database dump
--

-- Dumped from database version 11.6
-- Dumped by pg_dump version 12rc1

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

--
-- Name: Badges; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Badges" (
    "UserId" integer,
    "Name" character varying(600),
    "Date" date,
    "Id" integer NOT NULL
);


ALTER TABLE public."Badges" OWNER TO postgres;

--
-- Name: Comments; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Comments" (
    "Id" integer NOT NULL,
    "PostId" integer,
    "Score" integer,
    "Text" text,
    "UserDisplayName" character(600),
    "UserId" integer,
    "CreationDate" date
);


ALTER TABLE public."Comments" OWNER TO postgres;

--
-- Name: Post; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Post" (
    "Id" integer NOT NULL,
    "PostTypeId" integer,
    "CreationDate" date,
    "Score" integer,
    "Body" character(600),
    "LastEditDate" date,
    "LastActivityDate" date,
    "Title" character(600),
    "Tags" character(600),
    "AnswerId" integer
);


ALTER TABLE public."Post" OWNER TO postgres;

--
-- Name: PostFeedback; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."PostFeedback" (
    "Id" integer NOT NULL,
    "PostId" integer,
    "VoteTypeId" integer,
    "CreationDate" date
);


ALTER TABLE public."PostFeedback" OWNER TO postgres;

--
-- Name: PostHistory; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."PostHistory" (
    "Id" integer NOT NULL,
    "PostHistoryTypeId" integer,
    "PostId" integer,
    "CreationDate" date,
    "UserId" integer,
    "UserDisplayName" character(600),
    "Comment" text,
    "Text" text
);


ALTER TABLE public."PostHistory" OWNER TO postgres;

--
-- Name: PostHistoryTypes; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."PostHistoryTypes" (
    "Id" integer NOT NULL,
    "Name" character(600)
);


ALTER TABLE public."PostHistoryTypes" OWNER TO postgres;

--
-- Name: PostNotice; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."PostNotice" (
    "Id" integer NOT NULL,
    "PostId" integer,
    "PostNoticeTypeId" integer,
    "CreationDate" date,
    "Body" text
);


ALTER TABLE public."PostNotice" OWNER TO postgres;

--
-- Name: PostNoticeTypes; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."PostNoticeTypes" (
    "Id" integer NOT NULL,
    "ClassId" integer,
    "Name" character(600),
    "Body" text
);


ALTER TABLE public."PostNoticeTypes" OWNER TO postgres;

--
-- Name: PostTags; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."PostTags" (
    "PostId" integer,
    "TagId" integer
);


ALTER TABLE public."PostTags" OWNER TO postgres;

--
-- Name: PostTypes; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."PostTypes" (
    "Id" integer NOT NULL,
    "Name" character(600)
);


ALTER TABLE public."PostTypes" OWNER TO postgres;

--
-- Name: Reputation; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Reputation" (
    "Id" integer NOT NULL,
    "UserId" integer
);


ALTER TABLE public."Reputation" OWNER TO postgres;

--
-- Name: Tags; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Tags" (
    "Id" integer NOT NULL,
    "TagName" character(600),
    "Count" integer
);


ALTER TABLE public."Tags" OWNER TO postgres;

--
-- Name: Users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Users" (
    "Id" integer NOT NULL,
    "Reputation" integer,
    "CreationDate" date,
    "DisplayName" character varying(600),
    "LastAccessDate" character(1),
    "Location" character varying(600),
    "AboutMe" character varying(1000),
    "Views" integer,
    "WebsiteUrl" character varying(600),
    "ProfileImageUrl" character varying(600)
);


ALTER TABLE public."Users" OWNER TO postgres;

--
-- Name: VoteType; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."VoteType" (
    "Id" integer NOT NULL,
    "Name" character(600)
);


ALTER TABLE public."VoteType" OWNER TO postgres;

--
-- Name: Votes; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Votes" (
    "Id" integer NOT NULL,
    "PostId" integer,
    "VoteTypeId" integer,
    "UserId" integer,
    "CreationDate" date
);


ALTER TABLE public."Votes" OWNER TO postgres;

--
-- Data for Name: Badges; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Badges" VALUES (1, 'Gold', '2019-09-06', 1);
INSERT INTO public."Badges" VALUES (2, 'Bronze', '2019-11-12', 2);
INSERT INTO public."Badges" VALUES (3, 'Silver
', '2018-06-13', 3);


--
-- Data for Name: Comments; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Comments" VALUES (1, 1, 9, 'Laravel Homestead: “VM not created.. moving on”
', 'Frédéric Hamidi
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        ', 1, '2019-12-05');
INSERT INTO public."Comments" VALUES (2, 2, 253, 'The remote end hung up unexpectedly while git cloning
', 'Krishna Savani
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         ', 2, '2019-12-04');


--
-- Data for Name: Post; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Post" VALUES (1, 1, '2019-01-07', 3, 'I can see this in lsusbenter image description here but cannot find option to use it in users option in setting                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         ', '2019-11-07', '2019-12-08', 'How to use 27c6:538d Goodix FingerPrint (Dell Inspiron 5490)?                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           ', 'fingerprint-reader                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ', 1);
INSERT INTO public."Post" VALUES (2, 2, '2019-03-09', 2, 'Hi all I just wanted to know is it possible to enable a p2p-dev-wlan0(p2p interface) for miracast over infrastructure mode. I think from wpa_cli we can set ap_vendor_elements to append the beacon and probe response frames, but I''m not sure will it work with with the capability of p2p device interface. Any help would be appreciated.

I have a USB wifi adapter of rtl8812au chip set.                                                                                                                                                                                                                         ', '2019-10-11', '2019-12-07', 'Is there a way to set miracast over infrastructure mode for p2p interface                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               ', 'wpa-supplicant                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          ', NULL);


--
-- Data for Name: PostFeedback; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."PostFeedback" VALUES (1, 1, 1, '2019-01-07');
INSERT INTO public."PostFeedback" VALUES (2, 2, 2, '2019-03-09');


--
-- Data for Name: PostHistory; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."PostHistory" VALUES (1, 1, 1, '2019-01-07', 1, 'Frédéric Hamidi                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         ', 'Use bridge,

if Miracast streams from 192.168.0.2 and Router address is 192.168.0.1

Local subnet is 192.168.0.0/255.255.0.0', 'Hi all I just wanted to know is it possible to enable a p2p-dev-wlan0(p2p interface) for miracast over infrastructure mode. I think from wpa_cli we can set ap_vendor_elements to append the beacon and probe response frames, but I''m not sure will it work with with the capability of p2p device interface. Any help would be appreciated.

I have a USB wifi adapter of rtl8812au chip set.');


--
-- Data for Name: PostHistoryTypes; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."PostHistoryTypes" VALUES (1, 'Q                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       ');
INSERT INTO public."PostHistoryTypes" VALUES (2, 'A                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       ');
INSERT INTO public."PostHistoryTypes" VALUES (3, 'M                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       ');


--
-- Data for Name: PostNotice; Type: TABLE DATA; Schema: public; Owner: postgres
--



--
-- Data for Name: PostNoticeTypes; Type: TABLE DATA; Schema: public; Owner: postgres
--



--
-- Data for Name: PostTags; Type: TABLE DATA; Schema: public; Owner: postgres
--



--
-- Data for Name: PostTypes; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."PostTypes" VALUES (1, 'Q                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       ');
INSERT INTO public."PostTypes" VALUES (2, 'A                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       ');


--
-- Data for Name: Reputation; Type: TABLE DATA; Schema: public; Owner: postgres
--



--
-- Data for Name: Tags; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Tags" VALUES (1, 'fingerprint-reader                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ', 3);
INSERT INTO public."Tags" VALUES (2, 'inspiron                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                ', 4);
INSERT INTO public."Tags" VALUES (3, 'dell                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    ', 16);


--
-- Data for Name: Users; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Users" VALUES (1, 220754, '2018-11-11', 'Frédéric Hamidi', '1', 'France', 'Proud father of two.

I fell into programming when I was little and never looked back since then.

Languages of choice: C++, C#, Javascript, Python.

Operating systems: Windows, Linux.

Other interests: Linguistics, Japanese culture, American comic books.

Email: frederic.hamidi@gmail.com', 19920, 'http://stackoverflow.com/users/464709/fr%C3%A9d%C3%A9ric-hamidi?tab=profile', 'https://www.gravatar.com/avatar/0ab3363d257d780bd4c1f0c844b020a2?s=328&d=identicon&r=PG');
INSERT INTO public."Users" VALUES (2, 650, '2019-09-10', 'Krishna Savani', '2', NULL, 'Wordpress Developer at IBL Infotech
Apparently, this user prefers to keep an air of mystery about them.', 81, 'https://stackoverflow.com/users/11901310/krishna-savani', NULL);
INSERT INTO public."Users" VALUES (3, 171263, '2017-07-25', 'juergen d', '1', 'Germany', 'I learn a lot by participating on Stack Exchange. I like that!
', 12999, 'https://stackoverflow.com/users/575376/juergen-d', NULL);


--
-- Data for Name: VoteType; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."VoteType" VALUES (1, 'Useful                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ');
INSERT INTO public."VoteType" VALUES (2, 'Unuseful                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                ');


--
-- Data for Name: Votes; Type: TABLE DATA; Schema: public; Owner: postgres
--



--
-- Name: Badges Badges_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Badges"
    ADD CONSTRAINT "Badges_pkey" PRIMARY KEY ("Id");


--
-- Name: Comments Comments_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Comments"
    ADD CONSTRAINT "Comments_pkey" PRIMARY KEY ("Id");


--
-- Name: PostFeedback PostFeedback_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."PostFeedback"
    ADD CONSTRAINT "PostFeedback_pkey" PRIMARY KEY ("Id");


--
-- Name: PostHistoryTypes PostHistoryTypes_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."PostHistoryTypes"
    ADD CONSTRAINT "PostHistoryTypes_pkey" PRIMARY KEY ("Id");


--
-- Name: PostHistory PostHistory_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."PostHistory"
    ADD CONSTRAINT "PostHistory_pkey" PRIMARY KEY ("Id");


--
-- Name: PostNoticeTypes PostNoticeTypes_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."PostNoticeTypes"
    ADD CONSTRAINT "PostNoticeTypes_pkey" PRIMARY KEY ("Id");


--
-- Name: PostNotice PostNotice_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."PostNotice"
    ADD CONSTRAINT "PostNotice_pkey" PRIMARY KEY ("Id");


--
-- Name: PostTypes PostTypes_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."PostTypes"
    ADD CONSTRAINT "PostTypes_pkey" PRIMARY KEY ("Id");


--
-- Name: Post Post_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Post"
    ADD CONSTRAINT "Post_pkey" PRIMARY KEY ("Id");


--
-- Name: Reputation Reputation_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Reputation"
    ADD CONSTRAINT "Reputation_pkey" PRIMARY KEY ("Id");


--
-- Name: Tags Tags_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Tags"
    ADD CONSTRAINT "Tags_pkey" PRIMARY KEY ("Id");


--
-- Name: Users Users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Users"
    ADD CONSTRAINT "Users_pkey" PRIMARY KEY ("Id");


--
-- Name: VoteType VoteType_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."VoteType"
    ADD CONSTRAINT "VoteType_pkey" PRIMARY KEY ("Id");


--
-- Name: Votes Votes_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Votes"
    ADD CONSTRAINT "Votes_pkey" PRIMARY KEY ("Id");


--
-- Name: fki_AnswerId; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_AnswerId" ON public."Post" USING btree ("AnswerId");


--
-- Name: fki_PostHistoryTypeId; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_PostHistoryTypeId" ON public."PostHistory" USING btree ("PostHistoryTypeId");


--
-- Name: fki_PostId; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_PostId" ON public."Comments" USING btree ("PostId");


--
-- Name: fki_PostIdHistory; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_PostIdHistory" ON public."PostHistory" USING btree ("PostId");


--
-- Name: fki_PostId_Notice; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_PostId_Notice" ON public."PostNotice" USING btree ("PostId");


--
-- Name: fki_PostId_Tags; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_PostId_Tags" ON public."PostTags" USING btree ("PostId");


--
-- Name: fki_PostId_Vote; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_PostId_Vote" ON public."Votes" USING btree ("PostId");


--
-- Name: fki_PostNoticeTypeId; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_PostNoticeTypeId" ON public."PostNotice" USING btree ("PostNoticeTypeId");


--
-- Name: fki_PostTypeId; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_PostTypeId" ON public."Post" USING btree ("PostTypeId");


--
-- Name: fki_TagsId_Tags; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_TagsId_Tags" ON public."PostTags" USING btree ("TagId");


--
-- Name: fki_UserId; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_UserId" ON public."Badges" USING btree ("UserId");


--
-- Name: fki_UserIdHistory; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_UserIdHistory" ON public."PostHistory" USING btree ("UserId");


--
-- Name: fki_UserId_Reputation; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_UserId_Reputation" ON public."Reputation" USING btree ("UserId");


--
-- Name: fki_UserId_Vote; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_UserId_Vote" ON public."Votes" USING btree ("UserId");


--
-- Name: fki_VoteTypeId; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_VoteTypeId" ON public."Votes" USING btree ("VoteTypeId");


--
-- Name: PostHistory PostHistoryTypeId; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."PostHistory"
    ADD CONSTRAINT "PostHistoryTypeId" FOREIGN KEY ("PostHistoryTypeId") REFERENCES public."PostHistoryTypes"("Id") NOT VALID;


--
-- Name: Comments PostId; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Comments"
    ADD CONSTRAINT "PostId" FOREIGN KEY ("PostId") REFERENCES public."Post"("Id") NOT VALID;


--
-- Name: PostFeedback PostId; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."PostFeedback"
    ADD CONSTRAINT "PostId" FOREIGN KEY ("PostId") REFERENCES public."Post"("Id") NOT VALID;


--
-- Name: PostHistory PostId; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."PostHistory"
    ADD CONSTRAINT "PostId" FOREIGN KEY ("PostId") REFERENCES public."Post"("Id") NOT VALID;


--
-- Name: PostHistory PostIdHistory; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."PostHistory"
    ADD CONSTRAINT "PostIdHistory" FOREIGN KEY ("PostId") REFERENCES public."Post"("Id") NOT VALID;


--
-- Name: PostNotice PostId_Notice; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."PostNotice"
    ADD CONSTRAINT "PostId_Notice" FOREIGN KEY ("PostId") REFERENCES public."Post"("Id") NOT VALID;


--
-- Name: PostTags PostId_Tags; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."PostTags"
    ADD CONSTRAINT "PostId_Tags" FOREIGN KEY ("PostId") REFERENCES public."Post"("Id") NOT VALID;


--
-- Name: Votes PostId_Vote; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Votes"
    ADD CONSTRAINT "PostId_Vote" FOREIGN KEY ("PostId") REFERENCES public."Post"("Id") NOT VALID;


--
-- Name: PostNotice PostNoticeTypeId; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."PostNotice"
    ADD CONSTRAINT "PostNoticeTypeId" FOREIGN KEY ("PostNoticeTypeId") REFERENCES public."PostNoticeTypes"("Id") NOT VALID;


--
-- Name: Post PostTypeId; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Post"
    ADD CONSTRAINT "PostTypeId" FOREIGN KEY ("PostTypeId") REFERENCES public."PostTypes"("Id") NOT VALID;


--
-- Name: PostTags TagsId_Tags; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."PostTags"
    ADD CONSTRAINT "TagsId_Tags" FOREIGN KEY ("TagId") REFERENCES public."Tags"("Id") NOT VALID;


--
-- Name: Badges UserId; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Badges"
    ADD CONSTRAINT "UserId" FOREIGN KEY ("UserId") REFERENCES public."Users"("Id") NOT VALID;


--
-- Name: Comments UserId; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Comments"
    ADD CONSTRAINT "UserId" FOREIGN KEY ("UserId") REFERENCES public."Users"("Id") NOT VALID;


--
-- Name: PostHistory UserIdHistory; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."PostHistory"
    ADD CONSTRAINT "UserIdHistory" FOREIGN KEY ("UserId") REFERENCES public."Users"("Id") NOT VALID;


--
-- Name: Reputation UserId_Reputation; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Reputation"
    ADD CONSTRAINT "UserId_Reputation" FOREIGN KEY ("UserId") REFERENCES public."Users"("Id") NOT VALID;


--
-- Name: Votes UserId_Vote; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Votes"
    ADD CONSTRAINT "UserId_Vote" FOREIGN KEY ("UserId") REFERENCES public."Users"("Id") NOT VALID;


--
-- Name: Votes VoteTypeId; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Votes"
    ADD CONSTRAINT "VoteTypeId" FOREIGN KEY ("VoteTypeId") REFERENCES public."VoteType"("Id") NOT VALID;


--
-- PostgreSQL database dump complete
--

